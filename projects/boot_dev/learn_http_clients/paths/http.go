// package main
//
// import (
// 	"encoding/json"
// 	"fmt"
// 	"net/http"
// )
//
// func getResources(path string) []map[string]any {
// 	fullURL := "https://api.boot.dev"
//
// 	res, err := http.Get(fullURL + path)
// 	if err != nil {
// 		fmt.Println("Error creating request:", err)
// 		return nil
// 	}
//
// 	defer res.Body.Close()
//
// 	var resources []map[string]any
// 	decoder := json.NewDecoder(res.Body)
// 	err = decoder.Decode(&resources)
// 	if err != nil {
// 		fmt.Println("Error decoding response:", err)
// 		return nil
// 	}
//
// 	return resources
// }


package main

import (
	"encoding/json"
	"net/http"
)

func getUsers(url string) ([]User, error) {
	fullURL := url + "?sort=experience"
	res, err := http.Get(fullURL)
	if err != nil {
		return nil, err
	}
	defer res.Body.Close()

	var users []User
	decoder := json.NewDecoder(res.Body)
	err = decoder.Decode(&users)
	if err != nil {
		return nil, err
	}

	return users, nil
}

