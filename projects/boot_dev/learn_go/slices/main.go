// package main
//
// func getMessageWithRetries(primary, secondary, tertiary string) ([3]string, [3]int) {
// 	// ?
// 	arr_str := [3]string{primary, secondary, tertiary}
// 	arr_int := [3]int{len(primary), len(primary) + len(secondary), len(primary) + len(secondary) + len(tertiary)}
// 	return arr_str, arr_int
// }

// package main
//
// import (
// 	"errors"
// )
//
// const (
// 	planFree = "free"
// 	planPro  = "pro"
// )
//
// func getMessageWithRetriesForPlan(plan string, messages [3]string) ([]string, error) {
// 	// ?
// 	if plan == planPro {
// 		return messages[:],nil
// 	}
// 	if plan == planFree{
// 		return messages[:2],nil
// 	}
// 	return nil,errors.New("unsupported plan")
// }

package main

func getMessageCosts(messages []string) []float64 {
	// ?
	message_count := len(messages)
	costs_slice := make([]float64, message_count)
	for i := 0; i < message_count; i++ {
		costs_slice[i] = float64(len(messages[i])) * float64(0.01)
	}
	return costs_slice
}
