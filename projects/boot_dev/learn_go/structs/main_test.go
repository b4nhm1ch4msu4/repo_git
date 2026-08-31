// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func getMessageText(m messageToSend) string {
// 	return fmt.Sprintf("Sending message: '%s' to: %v", m.message, m.phoneNumber)
// }
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		phoneNumber int
// 		message     string
// 		expected    string
// 	}
//
// 	runCases := []testCase{
// 		{148255510981, "Thanks for signing up", "Sending message: 'Thanks for signing up' to: 148255510981"},
// 		{148255510982, "Love to have you aboard!", "Sending message: 'Love to have you aboard!' to: 148255510982"},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{148255510983, "We're so excited to have you", "Sending message: 'We're so excited to have you' to: 148255510983"},
// 		{148255510984, "", "Sending message: '' to: 148255510984"},
// 		{148255510985, "Hello, World!", "Sending message: 'Hello, World!' to: 148255510985"},
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
// 		output := getMessageText(messageToSend{
// 			phoneNumber: test.phoneNumber,
// 			message:     test.message,
// 		})
// 		if output != test.expected {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  %v
// Actual:     %v
// Fail
// `, test.phoneNumber, test.message, test.expected, output)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     (%v, %v)
// Expecting:  %v
// Actual:     %v
// Pass
// `, test.phoneNumber, test.message, test.expected, output)
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
// 		mToSend  messageToSend
// 		expected bool
// 	}
//
// 	runCases := []testCase{
// 		{messageToSend{
// 			message:   "you have an appointment tomorrow",
// 			sender:    user{name: "Brenda Halafax", number: 16545550987},
// 			recipient: user{name: "Sally Sue", number: 19035558973},
// 		}, true},
// 		{messageToSend{
// 			message:   "you have an event tomorrow",
// 			sender:    user{number: 16545550987},
// 			recipient: user{name: "Suzie Sall", number: 19035558973},
// 		}, false},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{messageToSend{
// 			message:   "you have an birthday tomorrow",
// 			sender:    user{name: "Jason Bjorn", number: 16545550987},
// 			recipient: user{name: "Jim Bond"},
// 		}, false},
// 		{messageToSend{
// 			message:   "you have a party tomorrow",
// 			sender:    user{name: "Njorn Halafax"},
// 			recipient: user{name: "Becky Sue", number: 19035558973},
// 		}, false},
// 		{messageToSend{
// 			message:   "you have a birthday tomorrow",
// 			sender:    user{name: "Eli Halafax", number: 16545550987},
// 			recipient: user{number: 19035558973},
// 		}, false},
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
// 		output := canSendMessage(test.mToSend)
// 		if output != test.expected {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:
//   * message:          %s
//   * sender.name:      %s
//   * sender.number:    %d
//   * recipient.name:   %s
//   * recipient.number: %d
//   Expected:           %v
//   Actual:             %v
// Fail
// `,
// 				test.mToSend.message,
// 				test.mToSend.sender.name,
// 				test.mToSend.sender.number,
// 				test.mToSend.recipient.name,
// 				test.mToSend.recipient.number,
// 				test.expected,
// 				output)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:
//   * message:          %s
//   * sender.name:      %s
//   * sender.number:    %d
//   * recipient.name:   %s
//   * recipient.number: %d
//   Expected:           %v
//   Actual:             %v
// Pass
// `,
// 				test.mToSend.message,
// 				test.mToSend.sender.name,
// 				test.mToSend.sender.number,
// 				test.mToSend.recipient.name,
// 				test.mToSend.recipient.number,
// 				test.expected,
// 				output)
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


// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func getSenderLog(s sender) string {
// 	return fmt.Sprintf(`
// ====================================
// Sender name: %v
// Sender number: %v
// Sender rateLimit: %v
// ====================================
// `, s.name, s.number, s.rateLimit)
// }
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		rateLimit int
// 		name      string
// 		number    int
// 		expected  string
// 	}
//
// 	runCases := []testCase{
// 		{
// 			10000,
// 			"Deborah",
// 			18055558790,
// 			`
// ====================================
// Sender name: Deborah
// Sender number: 18055558790
// Sender rateLimit: 10000
// ====================================
// `,
// 		},
// 		{
// 			5000,
// 			"Jason",
// 			18055558791,
// 			`
// ====================================
// Sender name: Jason
// Sender number: 18055558791
// Sender rateLimit: 5000
// ====================================
// `,
// 		},
// 	}
// 	submitCases := append(runCases, []testCase{
// 		{
// 			1000,
// 			"Jill",
// 			18055558792,
// 			`
// ====================================
// Sender name: Jill
// Sender number: 18055558792
// Sender rateLimit: 1000
// ====================================
// `,
// 		},
// 	}...)
//
// 	testCases := runCases
// 	if withSubmit {
// 		testCases = submitCases
// 	}
// 	skipped := len(submitCases) - len(testCases)
//
// 	passCount := 0
// 	failCount := 0
//
// 	for _, test := range testCases {
// 		output := getSenderLog(sender{
// 			rateLimit: test.rateLimit,
// 			user: user{
// 				name:   test.name,
// 				number: test.number,
// 			},
// 		})
// 		if output != test.expected {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     (%v, %v, %v)
// Expecting:  %v
// Actual:     %v
// Fail
// `, test.rateLimit, test.name, test.number, test.expected, output)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     (%v, %v, %v)
// Expecting:  %v
// Actual:     %v
// Pass
// `, test.rateLimit, test.name, test.number, test.expected, output)
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


// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func TestGetBasicAuth(t *testing.T) {
// 	type testCase struct {
// 		auth     authenticationInfo
// 		expected string
// 	}
//
// 	runCases := []testCase{
// 		{authenticationInfo{"Google", "12345"}, "Authorization: Basic Google:12345"},
// 		{authenticationInfo{"Bing", "98765"}, "Authorization: Basic Bing:98765"},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{authenticationInfo{"DDG", "76921"}, "Authorization: Basic DDG:76921"},
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
// 		output := test.auth.getBasicAuth()
// 		if output != test.expected {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     %+v
// Expecting:  %s
// Actual:     %s
// Fail
// `, test.auth, test.expected, output)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     %+v
// Expecting:  %s
// Actual:     %s
// Pass
// `, test.auth, test.expected, output)
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


// package main
//
// import (
// 	"fmt"
// 	"reflect"
// 	"testing"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		name     string
// 		expected uintptr
// 	}
//
// 	runCases := []testCase{
// 		{"contact", uintptr(24)},
// 		{"perms", uintptr(16)},
// 	}
//
// 	submitCases := append(runCases, []testCase{}...)
//
// 	skipped := len(submitCases) - len(runCases)
// 	passCount := 0
// 	failCount := 0
//
// 	for _, test := range submitCases {
// 		var typ reflect.Type
// 		if test.name == "contact" {
// 			typ = reflect.TypeOf(contact{
// 				userID:       "",
// 				sendingLimit: 0,
// 				age:          0,
// 			})
// 		} else if test.name == "perms" {
// 			typ = reflect.TypeOf(perms{
// 				permissionLevel: 0,
// 				canSend:         false,
// 				canReceive:      false,
// 				canManage:       false,
// 			})
// 		}
//
// 		size := typ.Size()
//
// 		if size != test.expected {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Inputs:     (%v)
// Expecting:  %v bytes
// Actual:     %v bytes
// Fail
// `, test.name, test.expected, size)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Inputs:     (%v)
// Expecting:  %v bytes
// Actual:     %v bytes
// Pass
// `, test.name, test.expected, size)
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


// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		name           string
// 		membershipType string
// 	}
//
// 	runCases := []testCase{
// 		{"Syl", "standard"},
// 		{"Pattern", "premium"},
// 		{"Pattern", "standard"},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{"Renarin", "standard"},
// 		{"Lift", "premium"},
// 		{"Dalinar", "standard"},
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
// 		user := newUser(test.name, test.membershipType)
//
// 		msgCharLimit := 100
// 		if test.membershipType == "premium" {
// 			msgCharLimit = 1000
// 		}
//
// 		if user.Name != test.name {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Test Failed (name):
// Inputs:     (name: %v, membershipType: %v)
// Expecting:  %v
// Actual:     %v
// `, test.name, test.membershipType, test.name, user.Name)
// 		} else if user.Type != test.membershipType {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Test Failed (membership type):
// Inputs:     (name: %v, membershipType: %v)
// Expecting:  %v
// Actual:     %v
// `, test.name, test.membershipType, test.membershipType, user.Type)
// 		} else if user.MessageCharLimit != msgCharLimit {
// 			failCount++
// 			t.Errorf(`---------------------------------
// Test Failed (message character limit):
// Inputs:     (name: %v, membershipType: %v)
// Expecting:  %v
// Actual:     %v
// `, test.name, test.membershipType, msgCharLimit, user.MessageCharLimit)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// Test Passed:
// Inputs:     (name: %v, membershipType: %v)
// Expecting:  %v, %v, %v
// Actual:     %v, %v, %v
// `, test.name, test.membershipType, test.name, test.membershipType, msgCharLimit, user.Name, user.Type, user.MessageCharLimit)
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
		name           string
		membershipType string
		message        string
		expectResult   string
		expectSuccess  bool
	}

	runCases := []testCase{
		{"Syl", "standard", "Hello, Kaladin!", "Hello, Kaladin!", true},
		{"Pattern", "premium", "You are not as good with patterns... You are abstract. You think in lies and tell them to yourselves. That is fascinating, but it is not good for patterns.", "You are not as good with patterns... You are abstract. You think in lies and tell them to yourselves. That is fascinating, but it is not good for patterns.", true},
		{"Dalinar", "standard", "I will take responsibility for what I have done. If I must fall, I will rise each time a better man.", "I will take responsibility for what I have done. If I must fall, I will rise each time a better man.", true},
	}

	submitCases := append(runCases, []testCase{
		{"Pattern", "standard", "Humans can see the world as it is not. It is why your lies can be so strong. You are able to not admit that they are lies.", "", false},
		{"Dabbid", "premium", ".........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................", "", false},
	}...)

	testCases := runCases
	if withSubmit {
		testCases = submitCases
	}

	skipped := len(submitCases) - len(testCases)

	passCount := 0
	failCount := 0

	for _, test := range testCases {
		user := newUser(test.name, test.membershipType)
		result, pass := user.SendMessage(test.message, len(test.message))
		if test.expectSuccess != pass || result != test.expectResult {
			failCount++
			t.Errorf(`---------------------------------
Test Failed:
* user:               %s
* membership type:    %s
* message:            %s
* expected result:    %s
* expected success:   %v
* actual result:      %s
* actual success:     %v
`, test.name, test.membershipType, test.message, test.expectResult, test.expectSuccess, result, pass)
		} else {
			passCount++
			fmt.Printf(`---------------------------------
Test Passed:
* user:               %s
* membership type:    %s
* message:            %s
* expected result:    %s
* expected success:   %v
* actual result:      %s
* actual success:     %v
`, test.name, test.membershipType, test.message, test.expectResult, test.expectSuccess, result, pass)
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

