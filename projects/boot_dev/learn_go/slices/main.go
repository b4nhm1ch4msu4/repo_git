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

// package main
//
// func getMessageCosts(messages []string) []float64 {
// 	// ?
// 	message_count := len(messages)
// 	costs_slice := make([]float64, message_count)
// 	for i := 0; i < message_count; i++ {
// 		costs_slice[i] = float64(len(messages[i])) * float64(0.01)
// 	}
// 	return costs_slice
// }

// package main
//
// type Message interface {
// 	Type() string
// }
//
// type TextMessage struct {
// 	Sender  string
// 	Content string
// }
//
// func (tm TextMessage) Type() string {
// 	return "text"
// }
//
// type MediaMessage struct {
// 	Sender    string
// 	MediaType string
// 	Content   string
// }
//
// func (mm MediaMessage) Type() string {
// 	return "media"
// }
//
// type LinkMessage struct {
// 	Sender  string
// 	URL     string
// 	Content string
// }
//
// func (lm LinkMessage) Type() string {
// 	return "link"
// }
//
// // Don't touch above this line
//
// func filterMessages(messages []Message, filterType string) []Message {
// 	// ?
// 	out := []Message{}
// 	for _,m := range messages {
// 		if m.Type() == filterType {
// 			out = append(out,m)
// 		}
// 	}
// 	return out
// }
//

// package main
//
// func isValidPassword(password string) bool {
// 	// ?
// 	leng_valid := false
// 	upper_valid := false
// 	digit_valid := false
//
// 	if len(password) >= 5 && len(password) <= 12 {
// 		leng_valid = true
// 	}
//
// 	for _, ch := range password {
// 		if ch >= '0' && ch <= '9' {
// 			digit_valid = true
// 		}
// 		if ch >= 'A' && ch <= 'Z' {
// 			upper_valid = true
// 		}
// 	}
//
// 	if leng_valid && upper_valid && digit_valid {
// 		return true
// 	}
// 	return false
// }

package main

import (
	"strings"
)

type sms struct {
	id      string
	content string
	tags    []string
}

func tagMessages(messages []sms, tagger func(sms) []string) []sms {
	// ?
	for i, m := range messages {
		m.tags = tagger(m)
		messages[i] = m
	}
	return messages
}

func tagger(msg sms) []string {
	tags := []string{}
	// ?
	c := msg.content
	c = strings.ToLower(c)
	if strings.Contains(c, "urgent") {
		tags = append(tags, "Urgent")
	}
	if strings.Contains(c, "sale") {
		tags = append(tags, "Promo")
	}

	return tags
}
