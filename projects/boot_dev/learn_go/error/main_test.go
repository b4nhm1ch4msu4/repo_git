// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		msgToCustomer string
// 		msgToSpouse   string
// 		expectedCost  int
// 		expectedErr   error
// 	}
//
// 	runCases := []testCase{
// 		{"Thanks for coming in to our flower shop today!", "We hope you enjoyed your gift.", 0, fmt.Errorf("can't send texts over 25 characters")},
// 		{"Thanks for joining us!", "Have a good day.", 76, nil},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{"Thank you.", "Enjoy!", 32, nil},
// 		{"We loved having you in!", "We hope the rest of your evening is fantastic.", 0, fmt.Errorf("can't send texts over 25 characters")},
// 	}...)
//
// 	testCases := runCases
// 	if withSubmit {
// 		testCases = submitCases
// 	}
//
// 	skipped := len(submitCases) - len(testCases)
// 	passCount := 0
// 	failCount := 0
//
// 	for _, test := range testCases {
// 		cost, err := sendSMSToCouple(test.msgToCustomer, test.msgToSpouse)
// 		errString := ""
// 		if err != nil {
// 			errString = err.Error()
// 		}
// 		expectedErrString := ""
// 		if test.expectedErr != nil {
// 			expectedErrString = test.expectedErr.Error()
// 		}
// 		if cost != test.expectedCost || errString != expectedErrString {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Fail
// `, test.msgToCustomer, test.msgToSpouse, test.expectedCost, test.expectedErr, cost, err)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Pass
// `, test.msgToCustomer, test.msgToSpouse, test.expectedCost, test.expectedErr, cost, err)
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
// 		cost      float64
// 		recipient string
// 		expected  string
// 	}
//
// 	runCases := []testCase{
// 		{1.4, "+1 (435) 555 0923", "SMS that costs $1.40 to be sent to '+1 (435) 555 0923' cannot be sent"},
// 		{2.1, "+2 (702) 555 3452", "SMS that costs $2.10 to be sent to '+2 (702) 555 3452' cannot be sent"},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{32.1, "+1 (801) 555 7456", "SMS that costs $32.10 to be sent to '+1 (801) 555 7456' cannot be sent"},
// 		{14.4, "+1 (234) 555 6545", "SMS that costs $14.40 to be sent to '+1 (234) 555 6545' cannot be sent"},
// 	}...)
//
// 	testCases := runCases
// 	if withSubmit {
// 		testCases = submitCases
// 	}
//
// 	skipped := len(submitCases) - len(testCases)
// 	passCount := 0
// 	failCount := 0
//
// 	for _, test := range testCases {
// 		output := getSMSErrorString(test.cost, test.recipient)
// 		if output != test.expected {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  %v
// Actual:     %v
// Fail
// `, test.cost, test.recipient, test.expected, output)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  %v
// Actual:     %v
// Pass
// `, test.cost, test.recipient, test.expected, output)
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
// func TestDivide(t *testing.T) {
// 	type testCase struct {
// 		dividend, divisor, expected float64
// 		expectedError               string
// 	}
//
// 	runCases := []testCase{
// 		{10, 2, 5, ""},
// 		{15, 3, 5, ""},
// 		{10, 0, 0, "cannot divide 10 by zero"},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{15, 0, 0, "cannot divide 15 by zero"},
// 		{100, 10, 10, ""},
// 		{16, 4, 4, ""},
// 		{30, 6, 5, ""},
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
// 		output, err := divide(test.dividend, test.divisor)
// 		var errString string
// 		if err != nil {
// 			errString = err.Error()
// 		}
// 		if output != test.expected || errString != test.expectedError {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Fail
// `, test.dividend, test.divisor, test.expected, test.expectedError, output, errString)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Pass
// `, test.dividend, test.divisor, test.expected, test.expectedError, output, errString)
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
// func TestDivide(t *testing.T) {
// 	type testCase struct {
// 		x, y, expected float64
// 		expectedErr    string
// 	}
//
// 	runCases := []testCase{
// 		{10, 0, 0, "no dividing by 0"},
// 		{10, 2, 5, ""},
// 		{15, 30, 0.5, ""},
// 		{6, 3, 2, ""},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{0, 10, 0, ""},
// 		{100, 0, 0, "no dividing by 0"},
// 		{-10, -2, 5, ""},
// 		{-10, 2, -5, ""},
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
// 		result, err := divide(test.x, test.y)
// 		errString := ""
// 		if err != nil {
// 			errString = err.Error()
// 		}
// 		if result != test.expected || errString != test.expectedErr {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Fail
// `, test.x, test.y, test.expected, test.expectedErr, result, errString)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  (%v, %v)
// Actual:     (%v, %v)
// Pass
// `, test.x, test.y, test.expected, test.expectedErr, result, errString)
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
	"errors"
	"fmt"
	"testing"
)

func TestValidateStatus(t *testing.T) {
	type testCase struct {
		status      string
		expectedErr error
	}

	runCases := []testCase{
		{"", errors.New("status cannot be empty")},
		{"This is a valid status update that is well within the character limit.", nil},
		{"This status update is way too long. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco.", errors.New("status exceeds 140 characters")},
	}

	submitCases := append(runCases, []testCase{
		{"Another valid status.", nil},
		{"This status update, while derivative, contains exactly one hundred and forty-one characters, which is over the status update character limit.", errors.New("status exceeds 140 characters")},
	}...)

	testCases := runCases
	if withSubmit {
		testCases = submitCases
	}

	skipped := len(submitCases) - len(testCases)
	passCount := 0
	failCount := 0

	for _, test := range testCases {
		err := validateStatus(test.status)

		passed := false
		if test.expectedErr == nil {
			passed = (err == nil)
		} else {
			passed = (err != nil && err.Error() == test.expectedErr.Error())
		}

		expectedStr := "<nil>"
		if test.expectedErr != nil {
			expectedStr = test.expectedErr.Error()
		}
		actualStr := "<nil>"
		if err != nil {
			actualStr = err.Error()
		}

		if !passed {
			failCount++
			t.Errorf(`---------------------------------
Inputs:     %v
Expecting:  %v
Actual:     %v
Fail
`, test.status, expectedStr, actualStr)
		} else {
			passCount++
			fmt.Printf(`---------------------------------
Inputs:     %v
Expecting:  %v
Actual:     %v
Pass
`, test.status, expectedStr, actualStr)
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

