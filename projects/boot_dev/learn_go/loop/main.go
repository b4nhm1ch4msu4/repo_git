// package main
//
// func bulkSend(numMessages int) float64 {
// 	// ?
// 	var total_cost float64 = 0
// 	for i := 0; i < numMessages; i++ {
// 		total_cost += 1.0 + 0.01 * float64(i)
// 	}
// 	return total_cost
// }

// package main
//
// func maxMessages(thresh int) int {
// 	// ?
// 	// max_mes := 0
// 	// cost := 100
// 	// for i := 1; cost <= thresh; i++ {
// 	// 	cost += 100 + i
// 	// 	max_mes += 1
// 	// }
//
// 	max_mes := 0
// 	cost := 0
// 	for i:=0;;i++ {
// 		cost += 100 + i
// 		if cost > thresh {
// 			break
// 		}
// 		max_mes += 1
// 	}
//
// 	return max_mes
// }

// package main
//
// func getMaxMessagesToSend(costMultiplier float64, budgetInPennies int) int {
// 	actualCostInPennies := 1.0
// 	maxMessagesToSend := 1
// 	balance := float64(budgetInPennies) - actualCostInPennies
// 	for balance >= 0 {
// 		actualCostInPennies *= costMultiplier
// 		balance -= actualCostInPennies
// 		maxMessagesToSend++
// 	}
// 	if balance < 0 {
// 		maxMessagesToSend--
// 	}
// 	return maxMessagesToSend
// }

package main

import "fmt"

func fizzbuzz() {
	// ?
	for i := 1; i <= 100; i++ {
		if i%3 == 0 && i%5 == 0 {
			fmt.Println("fizzbuzz")
			continue
		}
		if i%3 == 0 {
			fmt.Println("fizz")
			continue
		}
		if i%5 == 0 {
			fmt.Println("buzz")
			continue
		}
		fmt.Println(i)
	}
}

// don't touch below this line

func main() {
	fizzbuzz()
}
