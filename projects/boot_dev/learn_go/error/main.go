// package main
//
// import (
// 	"fmt"
// )
//
// func sendSMSToCouple(msgToCustomer, msgToSpouse string) (int, error) {
// 	// ?
// 	c, err := sendSMS(msgToCustomer)
// 	if err != nil {
// 		return 0, err
// 	}
// 	s, err := sendSMS(msgToSpouse)
// 	if err != nil {
// 		return 0, err
// 	}
// 	return (c+s),nil
// }
//
// // don't edit below this line
//
// func sendSMS(message string) (int, error) {
// 	const maxTextLen = 25
// 	const costPerChar = 2
// 	if len(message) > maxTextLen {
// 		return 0, fmt.Errorf("can't send texts over %v characters", maxTextLen)
// 	}
// 	return costPerChar * len(message), nil
// }
//

// package main
//
// import (
// 	"fmt"
// )
//
// func getSMSErrorString(cost float64, recipient string) string {
// 	// ?
// 	return fmt.Sprintf("SMS that costs $%.2f to be sent to '%s' cannot be sent",cost,recipient)
// }

// package main
//
// import (
// 	"fmt"
// )
//
// type divideError struct {
// 	dividend float64
// }
//
// // ?
// func (d divideError) Error() string {
// 	return fmt.Sprintf("cannot divide %v by zero", d.dividend)
// }
//
// func divide(dividend, divisor float64) (float64, error) {
// 	if divisor == 0 {
// 		return 0, divideError{dividend: dividend}
// 	}
// 	return dividend / divisor, nil
// }

// package main
//
// import (
// 	"errors"
// )
//
// func divide(x, y float64) (float64, error) {
// 	if y == 0 {
// 		// ?
// 		return 0,errors.New("no dividing by 0")
// 	}
// 	return x / y, nil
// }


package main

import (
	"errors"
)

func validateStatus(status string) error {
	// ?
	stt_len := len(status)
	if stt_len == 0 {
		return errors.New("status cannot be empty")
	}
	if stt_len > 140 {
		return errors.New("status exceeds 140 characters")
	}
	return nil
}

