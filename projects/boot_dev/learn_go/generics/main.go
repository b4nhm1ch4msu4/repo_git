// package main
//
// func getLast[T any](s []T) T {
// 	leng := len(s)
// 	if leng == 0 {
// 		var zero T
// 		return zero
// 	} else {
// 		return s[leng-1]
// 	}
// }

package main

import (
	"errors"
	"fmt"
	"time"
)

func chargeForLineItem[T lineItem](newItem T, oldItems []T, balance float64) ([]T, float64, error) {
	// ?
	newItemCost := newItem.GetCost()
	if newItemCost <= balance {
		oldItems = append(oldItems, newItem)
		newBalance := balance - newItemCost
		return oldItems, newBalance, nil
	} else {
		var emptyList []T
		var emptyBalance float64
		return emptyList, emptyBalance, errors.New("insufficient funds")
	}
}

// don't edit below this line

type lineItem interface {
	GetCost() float64
	GetName() string
}

type subscription struct {
	userEmail string
	startDate time.Time
	interval  string
}

func (s subscription) GetName() string {
	return fmt.Sprintf("%s subscription", s.interval)
}

func (s subscription) GetCost() float64 {
	if s.interval == "monthly" {
		return 25.00
	}
	if s.interval == "yearly" {
		return 250.00
	}
	return 0.0
}

type oneTimeUsagePlan struct {
	userEmail        string
	numEmailsAllowed int
}

func (otup oneTimeUsagePlan) GetName() string {
	return fmt.Sprintf("one time usage plan with %v emails", otup.numEmailsAllowed)
}

func (otup oneTimeUsagePlan) GetCost() float64 {
	const costPerEmail = 0.03
	return float64(otup.numEmailsAllowed) * costPerEmail
}
