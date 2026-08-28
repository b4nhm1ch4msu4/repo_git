// package main
//
// import (
// 	"fmt"
// 	"time"
// )
//
// func sendMessage(msg message) (string, int) {
// 	// ?
// 	content := msg.getMessage()
// 	cost := len(content) * 3
// 	return content, cost
// }
//
// type message interface {
// 	// ?
// 	getMessage() string
// }
//
// // don't edit below this line
//
// type birthdayMessage struct {
// 	birthdayTime  time.Time
// 	recipientName string
// }
//
// func (bm birthdayMessage) getMessage() string {
// 	return fmt.Sprintf("Hi %s, it is your birthday on %s", bm.recipientName, bm.birthdayTime.Format(time.RFC3339))
// }
//
// type sendingReport struct {
// 	reportName    string
// 	numberOfSends int
// }
//
// func (sr sendingReport) getMessage() string {
// 	return fmt.Sprintf(`Your "%s" report is ready. You've sent %v messages.`, sr.reportName, sr.numberOfSends)
// }


// package main
//
// type employee interface {
// 	getName() string
// 	getSalary() int
// }
//
// type contractor struct {
// 	name         string
// 	hourlyPay    int
// 	hoursPerYear int
// }
//
// func (c contractor) getName() string {
// 	return c.name
// }
//
// func (c contractor) getSalary() int {
// 	return c.hourlyPay * c.hoursPerYear
// }
//
// type fullTime struct {
// 	name   string
// 	salary int
// }
//
// func (ft fullTime) getSalary() int {
// 	return ft.salary
// }
//
// func (ft fullTime) getName() string {
// 	return ft.name
// }
//



package main

func (e email) cost() int {
	// ?
}

func (e email) format() string {
	// ?
}

type expense interface {
	cost() int
}

type formatter interface {
	format() string
}

type email struct {
	isSubscribed bool
	body         string
}
