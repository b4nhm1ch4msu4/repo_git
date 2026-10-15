// package main
//
// import (
// 	"fmt"
// 	"log"
// )
//
// func main() {
// 	url := "https://api.boot.dev/v1/courses_rest_api/learn-http/users"
//
// 	fmt.Print("Fetching users...\n")
//
// 	users, err := getUsers(url)
// 	if err != nil {
// 		log.Fatal("Error getting users:", err)
// 	}
// 	logUsers(users)
// }
//

// package main
//
// import (
// 	"encoding/json"
// 	"fmt"
// 	"math/rand"
// )
//
// func main() {
// 	userToCreate := User{
// 		Role:       "Junior Developer",
// 		Experience: 2,
// 		Remote:     true,
// 		User: struct {
// 			Name     string `json:"name"`
// 			Location string `json:"location"`
// 			Age      int    `json:"age"`
// 		}{
// 			Name:     "Dan",
// 			Location: "NOR",
// 			Age:      29,
// 		},
// 	}
//
// 	url := "https://api.boot.dev/v1/courses_rest_api/learn-http/users"
// 	apiKey := generateKey()
//
// 	fmt.Println("Retrieving user data...")
// 	userDataFirst, err := getUsers(url, apiKey)
// 	if err != nil {
// 		fmt.Println("Error retrieving users:", err)
// 		return
// 	}
// 	logUsers(userDataFirst)
// 	fmt.Println("---")
//
// 	fmt.Println("Creating new user...")
// 	creationResponse, err := createUser(url, apiKey, userToCreate)
// 	if err != nil {
// 		fmt.Println("Error creating user:", err)
// 		return
// 	}
// 	jsonData, _ := json.Marshal(creationResponse)
// 	fmt.Printf("Creation response body: %s\n", string(jsonData))
// 	fmt.Println("---")
//
// 	fmt.Println("Retrieving user data...")
// 	userDataSecond, err := getUsers(url, apiKey)
// 	if err != nil {
// 		fmt.Println("Error retrieving users:", err)
// 		return
// 	}
// 	logUsers(userDataSecond)
// 	fmt.Println("---")
// }
//
// func generateKey() string {
// 	const characters = "ABCDEF0123456789"
// 	result := ""
// 	rand.New(rand.NewSource(0))
// 	for i := 0; i < 16; i++ {
// 		result += string(characters[rand.Intn(len(characters))])
// 	}
// 	return result
// }
//

// package main
//
// import (
// 	"fmt"
// 	"math/rand"
// )
//
// func main() {
// 	userId := "2f8282cb-e2f9-496f-b144-c0aa4ced56db"
// 	baseURL := "https://api.boot.dev/v1/courses_rest_api/learn-http/users"
// 	apiKey := generateKey()
//
// 	userData, err := getUserById(baseURL, userId, apiKey)
// 	if err != nil {
// 		fmt.Println(err)
// 	}
// 	logUser(userData)
//
// 	fmt.Printf("Updating user with id: %s\n", userData.ID)
// 	userData.Role = "Senior Backend Developer"
// 	userData.Experience = 7
// 	userData.Remote = true
// 	userData.User.Name = "Allan"
//
// 	updatedUser, err := updateUser(baseURL, userId, apiKey, userData)
// 	if err != nil {
// 		fmt.Println(err)
// 		return
// 	}
// 	logUser(updatedUser)
// }
//
// func generateKey() string {
// 	const characters = "ABCDEF0123456789"
// 	result := ""
// 	rand.New(rand.NewSource(0))
// 	for i := 0; i < 16; i++ {
// 		result += string(characters[rand.Intn(len(characters))])
// 	}
// 	return result
// }

package main

import (
	"fmt"
	"log"
	"math/rand"
)

func main() {
	userId := "0194fdc2-fa2f-4cc0-81d3-ff12045b73c8"
	url := "https://api.boot.dev/v1/courses_rest_api/learn-http/users"
	apiKey := generateKey()

	users, err := getUsers(url, apiKey)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Logging user records:")
	logUsers(users)
	fmt.Println("---")

	err = deleteUser(url, userId, apiKey)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Deleted user with id: %s\n", userId)
	fmt.Println("---")

	newUsers, err := getUsers(url, apiKey)
	if err != nil {
		log.Fatal(err)
	}
	logUsers(newUsers)
	fmt.Println("---")
}

func generateKey() string {
	const characters = "ABCDEF0123456789"
	result := ""
	rand.New(rand.NewSource(0))
	for i := 0; i < 16; i++ {
		result += string(characters[rand.Intn(len(characters))])
	}
	return result
}

