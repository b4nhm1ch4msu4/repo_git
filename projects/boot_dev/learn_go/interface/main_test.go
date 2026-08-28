// package main
//
// import (
// 	"fmt"
// 	"testing"
// 	"time"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		msg          message
// 		expectedText string
// 		expectedCost int
// 	}
//
// 	runCases := []testCase{
// 		{
// 			birthdayMessage{time.Date(1994, 0o3, 21, 0, 0, 0, 0, time.UTC), "John Doe"},
// 			"Hi John Doe, it is your birthday on 1994-03-21T00:00:00Z",
// 			168,
// 		},
// 		{
// 			sendingReport{"First Report", 10},
// 			`Your "First Report" report is ready. You've sent 10 messages.`,
// 			183,
// 		},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{
// 			birthdayMessage{time.Date(1934, 0o5, 0o1, 0, 0, 0, 0, time.UTC), "Bill Deer"},
// 			"Hi Bill Deer, it is your birthday on 1934-05-01T00:00:00Z",
// 			171,
// 		},
// 		{
// 			sendingReport{"Second Report", 20},
// 			`Your "Second Report" report is ready. You've sent 20 messages.`,
// 			186,
// 		},
// 	}...)
//
// 	testCases := runCases
// 	if withSubmit {
// 		testCases = submitCases
// 	}
//
// 	skipped := len(submitCases) - len(testCases)
//
// 	passCount := 0
// 	failCount := 0
//
// 	for _, test := range testCases {
// 		text, cost := sendMessage(test.msg)
// 		if text != test.expectedText || cost != test.expectedCost {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     %+v
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Fail
// `, test.msg, test.expectedText, test.expectedCost, text, cost)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     %+v
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Pass
// `, test.msg, test.expectedText, test.expectedCost, text, cost)
// 		}
// 	}
//
// 	fmt.Println("---------------------------------")
// 	if skipped > 0 {
// 		fmt.Printf("%d passed, %d failed, %d skipped\n", passCount, failCount, skipped)
// 	} else {
// 		fmt.Printf("%d passed, %d failed\n", passCount, failCount)
// 	}
// }
//
// // withSubmit is set at compile time depending
// // on which button is used to run the tests
// var withSubmit = true
//


// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		emp      employee
// 		expected int
// 	}
//
// 	runCases := []testCase{
// 		{fullTime{name: "Bob", salary: 7300}, 7300},
// 		{contractor{name: "Jill", hourlyPay: 872, hoursPerYear: 982}, 856304},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{fullTime{name: "Alice", salary: 10000}, 10000},
// 		{contractor{name: "John", hourlyPay: 1000, hoursPerYear: 1000}, 1000000},
// 	}...)
//
// 	testCases := runCases
// 	if withSubmit {
// 		testCases = submitCases
// 	}
//
// 	skipped := len(submitCases) - len(testCases)
//
// 	passCount := 0
// 	failCount := 0
//
// 	for _, test := range testCases {
// 		salary := test.emp.getSalary()
// 		if salary != test.expected {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     %+v
// Expecting:  %v
// Actual:     %v
// Fail
// `, test.emp, test.expected, salary)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     %+v
// Expecting:  %v
// Actual:     %v
// Pass
// `, test.emp, test.expected, salary)
// 		}
// 	}
//
// 	fmt.Println("---------------------------------")
// 	if skipped > 0 {
// 		fmt.Printf("%d passed, %d failed, %d skipped\n", passCount, failCount, skipped)
// 	} else {
// 		fmt.Printf("%d passed, %d failed\n", passCount, failCount)
// 	}
// }
//
// // withSubmit is set at compile time depending
// // on which button is used to run the tests
// var withSubmit = true
//


package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	type testCase struct {
		body           string
		isSubscribed   bool
		expectedCost   int
		expectedFormat string
	}

	runCases := []testCase{
		{"hello there", true, 22, "'hello there' | Subscribed"},
		{"general kenobi", false, 70, "'general kenobi' | Not Subscribed"},
	}

	submitCases := append(runCases, []testCase{
		{"i hate sand", true, 22, "'i hate sand' | Subscribed"},
		{"it's coarse and rough and irritating", false, 180, "'it's coarse and rough and irritating' | Not Subscribed"},
		{"and it gets everywhere", true, 44, "'and it gets everywhere' | Subscribed"},
	}...)

	testCases := runCases
	if withSubmit {
		testCases = submitCases
	}

	skipped := len(submitCases) - len(testCases)

	passCount := 0
	failCount := 0

	for _, test := range testCases {
		e := email{
			body:         test.body,
			isSubscribed: test.isSubscribed,
		}
		cost := e.cost()
		format := e.format()
		if format != test.expectedFormat || cost != test.expectedCost {
			failCount++
			t.Errorf(`---------------------------------
Inputs:     (%v, %v)
Expecting:  (%v, %v)
Actual:     (%v, %v)
Fail
`, test.body, test.isSubscribed, test.expectedCost, test.expectedFormat, cost, format)
		} else {
			passCount++
			fmt.Printf(`---------------------------------
Inputs:     (%v, %v)
Expecting:  (%v, %v)
Actual:     (%v, %v)
Pass
`, test.body, test.isSubscribed, test.expectedCost, test.expectedFormat, cost, format)
		}
	}

	fmt.Println("---------------------------------")
	if skipped > 0 {
		fmt.Printf("%d passed, %d failed, %d skipped\n", passCount, failCount, skipped)
	} else {
		fmt.Printf("%d passed, %d failed\n", passCount, failCount)
	}
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true

