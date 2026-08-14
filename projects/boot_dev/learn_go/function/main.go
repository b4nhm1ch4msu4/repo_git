// package main
//
// import "fmt"
//
// func concat(s1 string, s2 string) string {
// 	return s1 + s2
// }
//
// // don't touch below this line
//
// func main() {
// 	test("Lane,", " happy birthday!")
// 	test("Zuck,", " hope that Metaverse thing works out")
// 	test("Go", " is fantastic")
// }
//
// func test(s1 string, s2 string) {
// 	fmt.Println(concat(s1, s2))
// }

//

package main

func getMonthlyPrice(tier string) int {
	switch tier {
	case "basic":
		return 10000
	case "premium":
		return 15000
	case "enterprise":
		return 50000
	default:
		return 0
	}
}
