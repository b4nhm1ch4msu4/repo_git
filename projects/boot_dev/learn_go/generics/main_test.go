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

// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func TestOrgBilling(t *testing.T) {
// 	type testCase struct {
// 		biller         orgBiller
// 		customer       org
// 		expectedAmount float64
// 		expectedEmail  string
// 	}
//
// 	runCases := []testCase{
// 		{
// 			biller: orgBiller{Plan: "pro"},
// 			customer: org{
// 				Admin: user{UserEmail: "jaskier@oxenfurt.com"},
// 				Name:  "Oxenfurt",
// 			},
// 			expectedAmount: 3000,
// 			expectedEmail:  "jaskier@oxenfurt.com",
// 		},
// 		{
// 			biller: orgBiller{Plan: "basic"},
// 			customer: org{
// 				Admin: user{UserEmail: "vernon@temeria.com"},
// 				Name:  "Temeria",
// 			},
// 			expectedAmount: 2000,
// 			expectedEmail:  "vernon@temeria.com",
// 		},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{
// 			biller: orgBiller{Plan: "pro"},
// 			customer: org{
// 				Admin: user{UserEmail: "fringilla@nilfgaard.com"},
// 				Name:  "Nilfgaard",
// 			},
// 			expectedAmount: 3000,
// 			expectedEmail:  "fringilla@nilfgaard.com",
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
// 	for i, test := range testCases {
// 		err := testBiller(test.biller, test.customer, test.expectedAmount, test.expectedEmail)
// 		if err != nil {
// 			failCount++
// 			t.Errorf(`---------------------------------
// OrgTest %d Failed:
// %v
// `, i, err)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// OrgTest %d Passed:
//   biller:   %v
//   customer: %v
// `, i, test.biller, test.customer)
// 		}
// 	}
//
// 	fmt.Println("---------------------------------")
// 	if skipped > 0 {
// 		fmt.Printf("OrgBilling: %d passed, %d failed, %d skipped\n", passCount, failCount, skipped)
// 	} else {
// 		fmt.Printf("OrgBilling: %d passed, %d failed\n", passCount, failCount)
// 	}
// }
//
// func TestUserBilling(t *testing.T) {
// 	type testCase struct {
// 		biller         userBiller
// 		customer       user
// 		expectedAmount float64
// 		expectedEmail  string
// 	}
//
// 	runCases := []testCase{
// 		{
// 			biller:         userBiller{Plan: "basic"},
// 			customer:       user{UserEmail: "vesemir@kaermorhen.com"},
// 			expectedAmount: 50,
// 			expectedEmail:  "vesemir@kaermorhen.com",
// 		},
// 		{
// 			biller:         userBiller{Plan: "pro"},
// 			customer:       user{UserEmail: "zoltan@mahakam.com"},
// 			expectedAmount: 100,
// 			expectedEmail:  "zoltan@mahakam.com",
// 		},
// 	}
//
// 	submitCases := append(runCases, []testCase{
// 		{
// 			biller:         userBiller{Plan: "pro"},
// 			customer:       user{UserEmail: "extra@submit.com"},
// 			expectedAmount: 100,
// 			expectedEmail:  "extra@submit.com",
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
// 	for i, test := range testCases {
// 		err := testBiller(test.biller, test.customer, test.expectedAmount, test.expectedEmail)
// 		if err != nil {
// 			failCount++
// 			t.Errorf(`---------------------------------
// UserTest %d Failed:
// %v
// `, i, err)
// 		} else {
// 			passCount++
// 			fmt.Printf(`---------------------------------
// UserTest %d Passed:
//   biller:   %v
//   customer: %v
// `, i, test.biller, test.customer)
// 		}
// 	}
//
// 	fmt.Println("---------------------------------")
// 	if skipped > 0 {
// 		fmt.Printf("UserBilling: %d passed, %d failed, %d skipped\n", passCount, failCount, skipped)
// 	} else {
// 		fmt.Printf("UserBilling: %d passed, %d failed\n", passCount, failCount)
// 	}
// }
//
// func testBiller[C customer](
// 	b biller[C],
// 	c C,
// 	expectedAmount float64,
// 	expectedEmail string,
// ) error {
// 	currentBill := b.Charge(c)
// 	name := b.Name()
//
// 	if currentBill.Amount != expectedAmount ||
// 		currentBill.Customer.GetBillingEmail() != expectedEmail {
// 		return fmt.Errorf(
// 			`biller "%v" FAILED:
//   biller Type:     %T
//   customer Type:   %T
//   customer:        %v
//   expected amount: %v
//   expected email:  %v
//   actual amount:   %v
//   actual email:    %v
// `,
// 			name,
// 			b,
// 			c,
// 			c,
// 			expectedAmount,
// 			expectedEmail,
// 			currentBill.Amount,
// 			currentBill.Customer.GetBillingEmail(),
// 		)
// 	}
//
// 	return nil
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
// 	"reflect"
// 	"testing"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		name string
// 		test func(*testing.T)
// 	}
// 	runCases := []testCase{
// 		{"email body", func(t *testing.T) {
// 			testEnvelopes(t, []string{"lane@example.com", "dax@example.com"}, "Welcome to Textio!")
// 		}},
// 		{"payment amount", func(t *testing.T) {
// 			testEnvelopes(t, []string{"billing@example.com"}, 750)
// 		}},
// 	}
// 	submitCases := append(runCases, []testCase{
// 		{"no recipients", func(t *testing.T) {
// 			testEnvelopes(t, []string{}, "Welcome to Textio!")
// 		}},
// 		{"duplicate recipients", func(t *testing.T) {
// 			testEnvelopes(t, []string{"billing@example.com", "billing@example.com"}, 0)
// 		}},
// 		{"structured notification", func(t *testing.T) {
// 			type notification struct {
// 				subject string
// 				tags    []string
// 			}
// 			testEnvelopes(t, []string{"allan@example.com", "lane@example.com", "dax@example.com"},
// 				notification{"Updated receipt", []string{"payment", "corrected"}},
// 			)
// 		}},
// 	}...)
//
// 	testCases := runCases
// 	if withSubmit {
// 		testCases = submitCases
// 	}
// 	passed, failed := 0, 0
// 	for i, tc := range testCases {
// 		fmt.Printf("---------------------------------\nEnvelopeTest %d (%s):\n", i, tc.name)
// 		if t.Run(tc.name, tc.test) {
// 			passed++
// 		} else {
// 			failed++
// 		}
// 	}
//
// 	fmt.Println("---------------------------------")
// 	skipped := len(submitCases) - len(testCases)
// 	if skipped > 0 {
// 		fmt.Printf("Envelopes: %d passed, %d failed, %d skipped\n", passed, failed, skipped)
// 	} else {
// 		fmt.Printf("Envelopes: %d passed, %d failed\n", passed, failed)
// 	}
// }
//
// func testEnvelopes[T any](t *testing.T, recipients []string, payload T) {
// 	t.Helper()
// 	var envelopes []envelope[T] = createEnvelopes(recipients, payload)
// 	fmt.Printf(`  recipients:       %q
//   payload:          %+v
//   expected count:   %d
//   actual count:     %d
// `, recipients, payload, len(recipients), len(envelopes))
// 	if len(envelopes) != len(recipients) {
// 		t.Fatal("envelope count does not match")
// 	}
// 	for i, e := range envelopes {
// 		var stored T = e.payload
// 		fmt.Printf(`  envelope %d:
//     expected recipient: %q
//     actual recipient:   %q
//     expected payload:   %+v
//     actual payload:     %+v
// `, i, recipients[i], e.recipient, payload, stored)
// 		if e.recipient != recipients[i] || !reflect.DeepEqual(stored, payload) {
// 			t.Errorf("envelope %d does not match", i)
// 		}
// 	}
// }
//
// var withSubmit = true


package main

import (
	"fmt"
	"reflect"
	"slices"
	"testing"
)

func Test(t *testing.T) {
	welcome := email{"lane@example.com", "Welcome"}
	reminder := email{"dax@example.com", "Reminder"}
	in := inbox{events: []any{receipt{750}, welcome, receipt{200}, reminder, welcome}}
	type testCase struct {
		name string
		test func(*testing.T)
	}
	runCases := []testCase{
		{"select emails", func(t *testing.T) {
			testSelect(t, in, []email{welcome, reminder, welcome})
		}},
		{"select receipts from the same inbox", func(t *testing.T) {
			testSelect(t, in, []receipt{{750}, {200}})
		}},
	}
	submitCases := append(runCases, []testCase{
		{"no matching events", func(t *testing.T) {
			testSelect(t, in, []string{})
		}},
		{"empty inbox", func(t *testing.T) {
			testSelect(t, inbox{}, []email{})
		}},
		{"zero values and unrelated events", func(t *testing.T) {
			mixed := inbox{events: []any{nil, receipt{0}, 0, receipt{125}, "receipt"}}
			testSelect(t, mixed, []receipt{{0}, {125}})
		}},
		{"a new event type", func(t *testing.T) {
			type notification struct {
				subject string
				tags    []string
			}
			first := notification{"Update", []string{"account", "email"}}
			second := notification{"Alert", []string{"billing"}}
			mixed := inbox{events: []any{welcome, first, receipt{500}, second}}
			testSelect(t, mixed, []notification{first, second})
		}},
	}...)

	testCases := runCases
	if withSubmit {
		testCases = submitCases
	}
	passed, failed := 0, 0
	for i, tc := range testCases {
		fmt.Printf("---------------------------------\nSelectTest %d (%s):\n", i, tc.name)
		if t.Run(tc.name, tc.test) {
			fmt.Println("  Passed")
			passed++
		} else {
			fmt.Println("  Failed")
			failed++
		}
	}
	fmt.Println("---------------------------------")
	skipped := len(submitCases) - len(testCases)
	if skipped > 0 {
		fmt.Printf("Select: %d passed, %d failed, %d skipped\n", passed, failed, skipped)
	} else {
		fmt.Printf("Select: %d passed, %d failed\n", passed, failed)
	}
}

func testSelect[T any](t *testing.T, in inbox, want []T) {
	t.Helper()
	original := slices.Clone(in.events)
	var got []T = in.Select[T]()
	fmt.Printf(`  requested type: %T
  inbox:          %+v
  expected:       %+v
  actual:         %+v
`, *new(T), original, want, got)
	if !reflect.DeepEqual(in.events, original) {
		t.Errorf("inbox changed: expected %+v, actual %+v", original, in.events)
	}
	if len(got) != len(want) {
		t.Fatalf("expected %d events, actual %d", len(want), len(got))
	}
	for i := range want {
		if !reflect.DeepEqual(got[i], want[i]) {
			t.Errorf("event %d: expected %+v, actual %+v", i, want[i], got[i])
		}
	}
}

var withSubmit = true

