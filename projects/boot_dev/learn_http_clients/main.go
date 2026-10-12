// package main
//
// import (
// 	"fmt"
// 	"io"
// 	"log"
// 	"net/http"
// )
//
// func main() {
// 	res, err := http.Get("https://api.boot.dev/v1/courses_rest_api/learn-http/issues?limit=1")
// 	if err != nil {
// 		log.Fatalf("error getting issue data: %v", err)
// 	}
//
// 	// Don't edit above this line
// 	defer res.Body.Close()
//
// 	data,err := io.ReadAll(res.Body)
//
// 	issues_str := string(data)
// 	fmt.Println(issues_str)
// 	// ?
// }

// package main
//
// import (
// 	"encoding/json"
// )
//
// func marshalAll[T any](items []T) ([][]byte, error) {
// 	var data [][]byte
// 	for _, v := range items {
// 		i, err := json.Marshal(v)
// 		if err != nil {
// 			return nil, err
// 		}
// 		data = append(data, i)
// 	}
// 	return data, nil
// }

package main

import (
	"fmt"
)

const baseUrl = "https://api.boot.dev"

func main() {
	issues, err := getResources(baseUrl + "/v1/courses_rest_api/learn-http/issues?limit=1")
	if err != nil {
		fmt.Println("Error getting issues:", err)
		return
	}
	fmt.Println("Issue:")
	logResources(issues)
	fmt.Println("---")

	projects, err := getResources(baseUrl + "/v1/courses_rest_api/learn-http/projects?limit=1")
	if err != nil {
		fmt.Println("Error getting projects:", err)
		return
	}
	fmt.Println("Project:")
	logResources(projects)
	fmt.Println("---")

	users, err := getResources(baseUrl + "/v1/courses_rest_api/learn-http/users?limit=1")
	if err != nil {
		fmt.Println("Error getting users:", err)
		return
	}
	fmt.Println("User:")
	logResources(users)
}

