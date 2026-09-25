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

package main

func countReports(numSentCh chan int) int {
	// ?
	counter := 0
	for {
		if num, ok := <-numSentCh; ok {
			counter += num
		} else {
			break
		}
	}
	return counter
}

// don't touch below this line

func sendReports(numBatches int, ch chan int) {
	for i := 0; i < numBatches; i++ {
		numReports := i*23 + 32%17
		ch <- numReports
	}
	close(ch)
}
