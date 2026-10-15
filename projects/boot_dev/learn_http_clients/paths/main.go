// package main
//
// import (
// 	"encoding/json"
// 	"fmt"
// )
//
// func main() {
// 	projects := getResources("/v1/courses_rest_api/learn-http/projects")
// 	fmt.Println("Projects:")
// 	logResources(projects)
// 	fmt.Println(" --- ")
//
// 	issues := getResources("/v1/courses_rest_api/learn-http/issues")
// 	fmt.Println("Issues:")
// 	logResources(issues)
// 	fmt.Println(" --- ")
//
// 	users := getResources("/v1/courses_rest_api/learn-http/users")
// 	fmt.Println("Users:")
// 	logResources(users)
// }
//
// func logResources(resources []map[string]any) {
// 	for _, resource := range resources {
// 		jsonResource, err := json.Marshal(resource)
// 		if err != nil {
// 			fmt.Println("Error marshalling resource:", err)
// 			continue
// 		}
// 		fmt.Printf(" - %s\n", jsonResource)
// 	}
// }

// package main
//
// import (
// 	"log"
// )
//
// func main() {
// 	baseURL := "https://api.boot.dev/v1/courses_rest_api/learn-http/users"
//
// 	users, err := getUsers(baseURL)
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	logUsers(users)
// }
//

package main

import "fmt"

func fetchTasks(baseURL, availability string) []Issue {
	// ?
	issue_limit := 0
	switch availability {
	case "Low":
		issue_limit = 1
	case "Medium":
		issue_limit = 3
	case "High":
		issue_limit = 5
	}
	fullURL := baseURL + fmt.Sprintf("?sort=estimate&limit=%v", issue_limit)
	return getIssues(fullURL)
}
