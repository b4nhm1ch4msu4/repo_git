// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		input    interface{}
// 		expected interface{}
// 	}
// 	runCases := []testCase{
// 		{[]int{}, 0},
// 		{[]bool{true, false, true, true, false}, false},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{[]int{1, 2, 3, 4}, 4},
// 		{[]string{"a", "b", "c", "d"}, "d"},
// 	}...)
//
// 	testCases := runCases
// 	if withSubmit {
// 		testCases = submitCases
// 	}
//
// 	skipped := len(submitCases) - len(testCases)
//
// 	passed, failed := 0, 0
//
// 	for _, test := range testCases {
// 		switch v := test.input.(type) {
// 		case []int:
// 			if output := getLast(v); output != test.expected {
// 				t.Errorf(
// 					`
// ---------------------------------
// Test Failed:
//   input:    %v
//   expected: %v
//   actual:   %v
// `,
// 					v,
// 					test.expected,
// 					output,
// 				)
// 				failed++
// 			} else {
// 				fmt.Printf(
// 					`
// ---------------------------------
// Test Passed:
//   input:    %v
//   expected: %v
//   actual:   %v
// `,
// 					v,
// 					test.expected,
// 					output,
// 				)
// 				passed++
// 			}
// 		case []string:
// 			if output := getLast(v); output != test.expected {
// 				t.Errorf(
// 					`---------------------------------
// Test Failed:
//   input:    %v
//   expected: %v
//   actual:   %v
// `,
// 					v,
// 					test.expected,
// 					output,
// 				)
// 				failed++
// 			} else {
// 				fmt.Printf(
// 					`---------------------------------
// Test Passed:
//   input:    %v
//   expected: %v
//   actual:   %v
// `,
// 					v,
// 					test.expected,
// 					output,
// 				)
// 				passed++
// 			}
// 		case []bool:
// 			if output := getLast(v); output != test.expected {
// 				t.Errorf(
// 					`---------------------------------
// Test Failed:
//   input:    %v
//   expected: %v
//   actual:   %v
// `,
// 					v,
// 					test.expected,
// 					output,
// 				)
// 				failed++
// 			} else {
// 				fmt.Printf(
// 					`---------------------------------
// Test Passed:
//   input:    %v
//   expected: %v
//   actual:   %v
// `,
// 					v,
// 					test.expected,
// 					output,
// 				)
// 				passed++
// 			}
// 		}
// 	}
//
// 	fmt.Println("---------------------------------")
// 	if skipped > 0 {
// 		fmt.Printf("%d passed, %d failed, %d skipped\n", passed, failed, skipped)
// 	} else {
// 		fmt.Printf("%d passed, %d failed\n", passed, failed)
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
// 	"slices"
// 	"testing"
// 	"time"
// )
//
// func TestChargeForLineItem(t *testing.T) {
// 	type testCase struct {
// 		newItem           lineItem
// 		oldItems          []lineItem
// 		balance           float64
// 		expected          []lineItem
// 		expectedBalance   float64
// 		expectedErrString string
// 	}
//
// 	runCases := []testCase{
// 		{
// 			newItem: subscription{
// 				userEmail: "geralt@rivia.com",
// 				startDate: time.Date(2021, 1, 1, 0, 0, 0, 0, time.UTC),
// 				interval:  "yearly",
// 			},
// 			oldItems: []lineItem{
// 				subscription{
// 					userEmail: "yen@vengerberg.com",
// 					startDate: time.Date(2021, 1, 1, 0, 0, 0, 0, time.UTC),
// 					interval:  "monthly",
// 				},
// 				oneTimeUsagePlan{
// 					userEmail:        "triss@maribor",
// 					numEmailsAllowed: 100,
// 				},
// 			},
// 			balance: 1000.00,
// 			expected: []lineItem{
// 				subscription{
// 					userEmail: "yen@vengerberg.com",
// 					startDate: time.Date(2021, 1, 1, 0, 0, 0, 0, time.UTC),
// 					interval:  "monthly",
// 				},
// 				oneTimeUsagePlan{
// 					userEmail:        "triss@maribor",
// 					numEmailsAllowed: 100,
// 				},
// 				subscription{
// 					userEmail: "geralt@rivia.com",
// 					startDate: time.Date(2021, 1, 1, 0, 0, 0, 0, time.UTC),
// 					interval:  "yearly",
// 				},
// 			},
// 			expectedBalance:   750.00,
// 			expectedErrString: "",
// 		},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{
// 			newItem: subscription{
// 				userEmail: "geralt@rivia.com",
// 				startDate: time.Date(2021, 1, 1, 0, 0, 0, 0, time.UTC),
// 				interval:  "yearly",
// 			},
// 			oldItems: []lineItem{
// 				subscription{
// 					userEmail: "yen@vengerberg.com",
// 					startDate: time.Date(2021, 1, 1, 0, 0, 0, 0, time.UTC),
// 					interval:  "monthly",
// 				},
// 				oneTimeUsagePlan{
// 					userEmail:        "triss@maribor",
// 					numEmailsAllowed: 100,
// 				},
// 			},
// 			balance:           200.00,
// 			expected:          nil,
// 			expectedBalance:   0.0,
// 			expectedErrString: "insufficient funds",
// 		},
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
// 		oldItems := append([]lineItem(nil), test.oldItems...)
// 		newItems, newBalance, err := chargeForLineItem(
// 			test.newItem,
// 			test.oldItems,
// 			test.balance,
// 		)
// 		if (err != nil && err.Error() != test.expectedErrString) ||
// 			(err == nil && test.expectedErrString != "") ||
// 			!slices.Equal(newItems, test.expected) ||
// 			newBalance != test.expectedBalance {
// 			failCount++
// 			t.Errorf(
// 				`---------------------------------
// Test Failed:
//   newItem:  %v
//   oldItems:
// %v
//   balance:  %v
//   expected items:
// %v
//   expected balance: %v
//   expected error:   %v
//   actual items:
// %v
//   actual balance: %v
//   actual error:   %v
// `,
// 				test.newItem,
// 				sliceWithBullets(oldItems),
// 				test.balance,
// 				sliceWithBullets(test.expected),
// 				test.expectedBalance,
// 				test.expectedErrString,
// 				sliceWithBullets(newItems),
// 				newBalance,
// 				err,
// 			)
// 		} else {
// 			passCount++
// 			fmt.Printf(
// 				`---------------------------------
// Test Passed:
//   newItem:  %v
//   oldItems:
// %v
//   balance:  %v
//   expected items:
// %v
//   expected balance: %v
//   expected error:   %v
//   actual items:
// %v
//   actual balance: %v
//   actual error:   %v
// `,
// 				test.newItem,
// 				sliceWithBullets(oldItems),
// 				test.balance,
// 				sliceWithBullets(test.expected),
// 				test.expectedBalance,
// 				test.expectedErrString,
// 				sliceWithBullets(newItems),
// 				newBalance,
// 				err,
// 			)
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
// func sliceWithBullets[T any](slice []T) string {
// 	if slice == nil {
// 		return "  <nil>"
// 	}
// 	if len(slice) == 0 {
// 		return "  []"
// 	}
// 	output := ""
// 	for i, item := range slice {
// 		form := "  - %v\n"
// 		if i == (len(slice) - 1) {
// 			form = "  - %v"
// 		}
// 		output += fmt.Sprintf(form, item)
// 	}
// 	return output
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

func TestOrgBilling(t *testing.T) {
	type testCase struct {
		biller         orgBiller
		customer       org
		expectedAmount float64
		expectedEmail  string
	}

	runCases := []testCase{
		{
			biller: orgBiller{Plan: "pro"},
			customer: org{
				Admin: user{UserEmail: "jaskier@oxenfurt.com"},
				Name:  "Oxenfurt",
			},
			expectedAmount: 3000,
			expectedEmail:  "jaskier@oxenfurt.com",
		},
		{
			biller: orgBiller{Plan: "basic"},
			customer: org{
				Admin: user{UserEmail: "vernon@temeria.com"},
				Name:  "Temeria",
			},
			expectedAmount: 2000,
			expectedEmail:  "vernon@temeria.com",
		},
	}

	submitCases := append(runCases, []testCase{
		{
			biller: orgBiller{Plan: "pro"},
			customer: org{
				Admin: user{UserEmail: "fringilla@nilfgaard.com"},
				Name:  "Nilfgaard",
			},
			expectedAmount: 3000,
			expectedEmail:  "fringilla@nilfgaard.com",
		},
	}...)

	testCases := runCases
	if withSubmit {
		testCases = submitCases
	}

	skipped := len(submitCases) - len(testCases)
	passCount := 0
	failCount := 0

	for i, test := range testCases {
		err := testBiller(test.biller, test.customer, test.expectedAmount, test.expectedEmail)
		if err != nil {
			failCount++
			t.Errorf(`---------------------------------
OrgTest %d Failed:
%v
`, i, err)
		} else {
			passCount++
			fmt.Printf(`---------------------------------
OrgTest %d Passed:
  biller:   %v
  customer: %v
`, i, test.biller, test.customer)
		}
	}

	fmt.Println("---------------------------------")
	if skipped > 0 {
		fmt.Printf("OrgBilling: %d passed, %d failed, %d skipped\n", passCount, failCount, skipped)
	} else {
		fmt.Printf("OrgBilling: %d passed, %d failed\n", passCount, failCount)
	}
}

func TestUserBilling(t *testing.T) {
	type testCase struct {
		biller         userBiller
		customer       user
		expectedAmount float64
		expectedEmail  string
	}

	runCases := []testCase{
		{
			biller:         userBiller{Plan: "basic"},
			customer:       user{UserEmail: "vesemir@kaermorhen.com"},
			expectedAmount: 50,
			expectedEmail:  "vesemir@kaermorhen.com",
		},
		{
			biller:         userBiller{Plan: "pro"},
			customer:       user{UserEmail: "zoltan@mahakam.com"},
			expectedAmount: 100,
			expectedEmail:  "zoltan@mahakam.com",
		},
	}

	submitCases := append(runCases, []testCase{
		{
			biller:         userBiller{Plan: "pro"},
			customer:       user{UserEmail: "extra@submit.com"},
			expectedAmount: 100,
			expectedEmail:  "extra@submit.com",
		},
	}...)

	testCases := runCases
	if withSubmit {
		testCases = submitCases
	}

	skipped := len(submitCases) - len(testCases)
	passCount := 0
	failCount := 0

	for i, test := range testCases {
		err := testBiller(test.biller, test.customer, test.expectedAmount, test.expectedEmail)
		if err != nil {
			failCount++
			t.Errorf(`---------------------------------
UserTest %d Failed:
%v
`, i, err)
		} else {
			passCount++
			fmt.Printf(`---------------------------------
UserTest %d Passed:
  biller:   %v
  customer: %v
`, i, test.biller, test.customer)
		}
	}

	fmt.Println("---------------------------------")
	if skipped > 0 {
		fmt.Printf("UserBilling: %d passed, %d failed, %d skipped\n", passCount, failCount, skipped)
	} else {
		fmt.Printf("UserBilling: %d passed, %d failed\n", passCount, failCount)
	}
}

func testBiller[C customer](
	b biller[C],
	c C,
	expectedAmount float64,
	expectedEmail string,
) error {
	currentBill := b.Charge(c)
	name := b.Name()

	if currentBill.Amount != expectedAmount ||
		currentBill.Customer.GetBillingEmail() != expectedEmail {
		return fmt.Errorf(
			`biller "%v" FAILED:
  biller Type:     %T
  customer Type:   %T
  customer:        %v
  expected amount: %v
  expected email:  %v
  actual amount:   %v
  actual email:    %v
`,
			name,
			b,
			c,
			c,
			expectedAmount,
			expectedEmail,
			currentBill.Amount,
			currentBill.Customer.GetBillingEmail(),
		)
	}

	return nil
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true

