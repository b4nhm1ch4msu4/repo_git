// package main
//
// import (
// 	"fmt"
// 	"time"
// )
//
// func sendEmail(message string) {
// 	go func() {
// 		time.Sleep(time.Millisecond * 250)
// 		fmt.Printf("Email received: '%s'\n", message)
// 	}()
// 	fmt.Printf("Email sent: '%s'\n", message)
// }
//
// // Don't touch below this line
//
// func test(message string) {
// 	sendEmail(message)
// 	time.Sleep(time.Millisecond * 500)
// 	fmt.Println("========================")
// }
//
// func main() {
// 	test("Hello there Kaladin!")
// 	test("Hi there Shallan!")
// 	test("Hey there Dalinar!")
// }

// package main
//
// import (
// 	"time"
// )
//
// type email struct {
// 	body string
// 	date time.Time
// }
//
// func checkEmailAge(emails [3]email) [3]bool {
// 	isOldChan := make(chan bool)
//
// 	go sendIsOld(isOldChan, emails)
//
// 	isOld := [3]bool{}
// 	isOld[0] = <-isOldChan
// 	isOld[1] = <-isOldChan
// 	isOld[2] = <-isOldChan
// 	return isOld
// }
//
// // don't touch below this line
//
// func sendIsOld(isOldChan chan<- bool, emails [3]email) {
// 	for _, e := range emails {
// 		if e.date.Before(time.Date(2020, 0, 0, 0, 0, 0, 0, time.UTC)) {
// 			isOldChan <- true
// 			continue
// 		}
// 		isOldChan <- false
// 	}
// }

// package main
//
// import "fmt"
//
// func waitForDBs(numDBs int, dbChan chan struct{}) {
// 	for i := 0; i < numDBs; i++ {
// 		<-dbChan
// 	}
// }
//
// // don't touch below this line
//
// func getDBsChannel(numDBs int) (chan struct{}, *int) {
// 	count := 0
// 	ch := make(chan struct{})
//
// 	go func() {
// 		for i := 0; i < numDBs; i++ {
// 			ch <- struct{}{}
// 			fmt.Printf("Database %v is online\n", i+1)
// 			count++
// 		}
// 	}()
//
// 	return ch, &count
// }

// package main
//
// func addEmailsToQueue(emails []string) chan string {
// 	// ?
// 	leng := len(emails)
// 	ch := make(chan string, leng)
// 	for _, s := range emails {
// 		ch <- s
// 	}
// 	return ch
// }

// package main
//
// func countReports(numSentCh chan int) int {
// 	// ?
// 	counter := 0
// 	for {
// 		if num, ok := <-numSentCh; ok {
// 			counter += num
// 		} else {
// 			break
// 		}
// 	}
// 	return counter
// }
//
// // don't touch below this line
//
// func sendReports(numBatches int, ch chan int) {
// 	for i := 0; i < numBatches; i++ {
// 		numReports := i*23 + 32%17
// 		ch <- numReports
// 	}
// 	close(ch)
// }

// package main
//
// func concurrentFib(n int) []int {
// 	// ?
// 	out := []int{}
// 	ch := make(chan int)
// 	go fibonacci(n, ch)
// 	for item := range ch {
// 		out = append(out, item)
// 	}
// 	return out
//
// }
//
// // don't touch below this line
//
// func fibonacci(n int, ch chan int) {
// 	x, y := 0, 1
// 	for i := 0; i < n; i++ {
// 		ch <- x
// 		x, y = y, x+y
// 	}
// 	close(ch)
// }

// package main
//
// import (
// 	"fmt"
// 	"math/rand"
// 	"time"
// )
//
// func logMessages(chEmails, chSms chan string) {
// 	// ?
// 	for {
// 		select {
// 		case e, ok := <-chEmails:
// 			if ok {
// 				logEmail(e)
// 			} else {
// 				return
// 			}
// 		case s, ok := <-chSms:
// 			if ok {
// 				logSms(s)
// 			} else {
// 				return
// 			}
// 		}
// 	}
// }
//
// // don't touch below this line
//
// func logSms(sms string) {
// 	fmt.Println("SMS:", sms)
// }
//
// func logEmail(email string) {
// 	fmt.Println("Email:", email)
// }
//
// func test(sms []string, emails []string) {
// 	fmt.Println("Starting...")
//
// 	chSms, chEmails := sendToLogger(sms, emails)
//
// 	logMessages(chEmails, chSms)
// 	fmt.Println("===============================")
// }
//
// func main() {
// 	test(
// 		[]string{
// 			"hi friend",
// 			"What's going on?",
// 			"Welcome to the business",
// 			"I'll pay you to be my friend",
// 		},
// 		[]string{
// 			"Will you make your appointment?",
// 			"Let's be friends",
// 			"What are you doing?",
// 			"I can't believe you've done this.",
// 		},
// 	)
// 	test(
// 		[]string{
// 			"this song slaps hard",
// 			"yooo hoooo",
// 			"i'm a big fan",
// 		},
// 		[]string{
// 			"What do you think of this song?",
// 			"I hate this band",
// 			// "Can you believe this song?",
// 		},
// 	)
// }
//
// func sendToLogger(sms, emails []string) (chSms, chEmails chan string) {
// 	chSms = make(chan string)
// 	chEmails = make(chan string)
// 	randReader := rand.New(rand.NewSource(0))
// 	go func() {
// 		for i := 0; i < len(sms) && i < len(emails); i++ {
// 			done := make(chan struct{})
// 			s := sms[i]
// 			e := emails[i]
// 			t1 := time.Millisecond * time.Duration(randReader.Intn(1000))
// 			t2 := time.Millisecond * time.Duration(randReader.Intn(1000))
// 			go func() {
// 				time.Sleep(t1)
// 				chSms <- s
// 				done <- struct{}{}
// 			}()
// 			go func() {
// 				time.Sleep(t2)
// 				chEmails <- e
// 				done <- struct{}{}
// 			}()
// 			<-done
// 			<-done
// 			time.Sleep(10 * time.Millisecond)
// 		}
// 		close(chSms)
// 		close(chEmails)
// 	}()
// 	return chSms, chEmails
// }

package main

import (
	"time"
)

func saveBackups(snapshotTicker, saveAfter <-chan time.Time, logChan chan string) {
	// ?
	for {
		select {
		case _, ok := <-snapshotTicker:
			if ok {
				takeSnapshot(logChan)
			}
		case _, ok := <-saveAfter:
			if ok {
				saveSnapshot(logChan)
				return
			}
		default:
			waitForData(logChan)
			time.Sleep(500 * time.Millisecond)
		}
	}
}

// don't touch below this line

func takeSnapshot(logChan chan string) {
	logChan <- "Taking a backup snapshot..."
}

func saveSnapshot(logChan chan string) {
	logChan <- "All backups saved!"
	close(logChan)
}

func waitForData(logChan chan string) {
	logChan <- "Nothing to do, waiting..."
}
