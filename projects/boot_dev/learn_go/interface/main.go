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

// package main
// import "fmt"
//
// func (e email) cost() int {
// 	// ?
// 	if e.isSubscribed {
// 		return len(e.body) * 2
// 	}
// 	return len(e.body) * 5
// }
//
// func (e email) format() string {
// 	// ?
// 	if e.isSubscribed {
// 		return fmt.Sprintf("'%s' | Subscribed",e.body)
// 	}
// 		return fmt.Sprintf("'%s' | Not Subscribed",e.body)
// }
//
// type expense interface {
// 	cost() int
// }
//
// type formatter interface {
// 	format() string
// }
//
// type email struct {
// 	isSubscribed bool
// 	body         string
// }

// package main
//
// func getExpenseReport(e expense) (string, float64) {
// 	// ?
// 	m, ok := e.(email)
// 	if ok {
// 		return m.toAddress, m.cost()
// 	}
//
// 	s, ok := e.(sms)
// 	if ok {
// 		return s.toPhoneNumber, s.cost()
// 	}
//
// 	return "", 0.0
// }
//
// // don't touch below this line
//
// type expense interface {
// 	cost() float64
// }
//
// type email struct {
// 	isSubscribed bool
// 	body         string
// 	toAddress    string
// }
//
// type sms struct {
// 	isSubscribed  bool
// 	body          string
// 	toPhoneNumber string
// }
//
// type invalid struct{}
//
// func (em email) cost() float64 {
// 	if !em.isSubscribed {
// 		return float64(len(em.body)) * .05
// 	}
// 	return float64(len(em.body)) * .01
// }
//
// func (sm sms) cost() float64 {
// 	if !sm.isSubscribed {
// 		return float64(len(sm.body)) * .1
// 	}
// 	return float64(len(sm.body)) * .03
// }
//
// func (inv invalid) cost() float64 {
// 	return 0.0
// }

// package main
//
// import "fmt"
//
// type formatter interface {
// 	format() string
// }
//
// type plainText struct {
// 	message string
// }
//
// func (obj plainText) format() string {
// 	return obj.message
// }
//
// type bold struct {
// 	message string
// }
//
// func (obj bold) format() string {
// 	return fmt.Sprintf("**%s**",obj.message)
// }
//
// type code struct {
// 	message string
// }
//
// func (obj code) format() string {
// 	return fmt.Sprintf("`%s`",obj.message)
// }
//
// // Don't Touch below this line
//
// func sendMessage(format formatter) string {
// 	return format.format() // Adjusted to call Format without an argument
// }

package main

type notification interface {
	importance() int
}

type directMessage struct {
	senderUsername string
	messageContent string
	priorityLevel  int
	isUrgent       bool
}

type groupMessage struct {
	groupName      string
	messageContent string
	priorityLevel  int
}

type systemAlert struct {
	alertCode      string
	messageContent string
}

func (m directMessage) importance() int {
	if m.isUrgent {
		return 50
	}
	return m.priorityLevel
}

func (m groupMessage) importance() int {
	return m.priorityLevel
}

func (m systemAlert) importance() int {
	return 100
}

// ?

func processNotification(n notification) (string, int) {
	// ?
	switch n.(type) {
	case directMessage:
		dm, _ := n.(directMessage)
		return dm.senderUsername, dm.importance()
	case groupMessage:
		gm, _ := n.(groupMessage)
		return gm.groupName, gm.importance()
	case systemAlert:
		sa, _ := n.(systemAlert)
		return sa.alertCode, sa.importance()
	default:
		return "", 0
	}
}
