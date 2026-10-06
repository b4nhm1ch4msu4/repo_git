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

// package main
//
// import (
// 	"errors"
// 	"fmt"
// 	"time"
// )
//
// func chargeForLineItem[T lineItem](newItem T, oldItems []T, balance float64) ([]T, float64, error) {
// 	// ?
// 	newItemCost := newItem.GetCost()
// 	if newItemCost <= balance {
// 		oldItems = append(oldItems, newItem)
// 		newBalance := balance - newItemCost
// 		return oldItems, newBalance, nil
// 	} else {
// 		var emptyList []T
// 		var emptyBalance float64
// 		return emptyList, emptyBalance, errors.New("insufficient funds")
// 	}
// }
//
// // don't edit below this line
//
// type lineItem interface {
// 	GetCost() float64
// 	GetName() string
// }
//
// type subscription struct {
// 	userEmail string
// 	startDate time.Time
// 	interval  string
// }
//
// func (s subscription) GetName() string {
// 	return fmt.Sprintf("%s subscription", s.interval)
// }
//
// func (s subscription) GetCost() float64 {
// 	if s.interval == "monthly" {
// 		return 25.00
// 	}
// 	if s.interval == "yearly" {
// 		return 250.00
// 	}
// 	return 0.0
// }
//
// type oneTimeUsagePlan struct {
// 	userEmail        string
// 	numEmailsAllowed int
// }
//
// func (otup oneTimeUsagePlan) GetName() string {
// 	return fmt.Sprintf("one time usage plan with %v emails", otup.numEmailsAllowed)
// }
//
// func (otup oneTimeUsagePlan) GetCost() float64 {
// 	const costPerEmail = 0.03
// 	return float64(otup.numEmailsAllowed) * costPerEmail
// }

package main

import (
	"fmt"
)

type biller[C customer] interface {
	//?
	Charge(C) bill
	Name() string
}

// don't edit below this line

type userBiller struct {
	Plan string
}

func (ub userBiller) Charge(u user) bill {
	amount := 50.0
	if ub.Plan == "pro" {
		amount = 100.0
	}
	return bill{
		Customer: u,
		Amount:   amount,
	}
}

func (sb userBiller) Name() string {
	return fmt.Sprintf("%s user biller", sb.Plan)
}

type orgBiller struct {
	Plan string
}

func (ob orgBiller) Name() string {
	return fmt.Sprintf("%s org biller", ob.Plan)
}

func (ob orgBiller) Charge(o org) bill {
	amount := 2000.0
	if ob.Plan == "pro" {
		amount = 3000.0
	}
	return bill{
		Customer: o,
		Amount:   amount,
	}
}

type customer interface {
	GetBillingEmail() string
}

type bill struct {
	Customer customer
	Amount   float64
}

type user struct {
	UserEmail string
}

func (u user) GetBillingEmail() string {
	return u.UserEmail
}

type org struct {
	Admin user
	Name  string
}

func (o org) GetBillingEmail() string {
	return o.Admin.GetBillingEmail()
}

