// package main
//
// import (
// 	"encoding/json"
// 	"net/http"
// )
//
// func getUsers(url string) ([]User, error) {
// 	// ?
// 	resp, err := http.Get(url)
// 	if err != nil {
// 		return nil, err
// 	}
// 	var user []User
// 	decoder := json.NewDecoder(resp.Body)
// 	if err := decoder.Decode(&user); err != nil {
// 		return nil, err
// 	}
// 	return user, nil
// }

// package main
//
// import (
// 	"bytes"
// 	"encoding/json"
// 	"net/http"
// )
//
// func createUser(url, apiKey string, data User) (User, error) {
// 	// ?
// 	jsonData, err := json.Marshal(data)
// 	if err != nil {
// 		return User{}, err
// 	}
//
// 	req, err := http.NewRequest("POST", url, bytes.NewBuffer(jsonData))
// 	if err != nil {
// 		return User{}, err
// 	}
//
// 	req.Header.Add("Content-Type", "application/json")
// 	req.Header.Add("X-API-Key", apiKey)
//
// 	client := &http.Client{}
// 	res, err := client.Do(req)
// 	if err != nil {
// 		return User{}, err
// 	}
//
// 	var user User
// 	decoder := json.NewDecoder(res.Body)
// 	err = decoder.Decode(&user)
// 	if err != nil {
// 		return User{}, err
// 	}
// 	return user, nil
// }

// package main
//
// import (
// 	"bytes"
// 	"encoding/json"
// 	"net/http"
// )
//
// func updateUser(baseURL, id, apiKey string, data User) (User, error) {
// 	fullURL := baseURL + "/" + id
//
// 	// ?
// 	jsonData, err := json.Marshal(data)
// 	if err != nil {
// 		return User{}, err
// 	}
// 	req, err := http.NewRequest("PUT", fullURL, bytes.NewBuffer(jsonData))
// 	if err != nil {
// 		return User{}, err
// 	}
// 	req.Header.Set("Content-Type", "application/json")
// 	req.Header.Set("X-API-Key", apiKey)
//
// 	client := &http.Client{}
// 	res, err := client.Do(req)
// 	if err != nil {
// 		return User{}, err
// 	}
// 	defer res.Body.Close()
//
// 	var user User
// 	decoder := json.NewDecoder(res.Body)
// 	err = decoder.Decode(&user)
// 	if err != nil {
// 		return User{}, err
// 	}
//
// 	return user, nil
// }
//
// func getUserById(baseURL, id, apiKey string) (User, error) {
// 	fullURL := baseURL + "/" + id
//
// 	// ?
// 	req, err := http.NewRequest("GET", fullURL, nil)
// 	if err != nil {
// 		return User{}, err
// 	}
// 	req.Header.Set("X-API-Key", apiKey)
//
// 	client := &http.Client{}
// 	res, err := client.Do(req)
// 	if err != nil {
// 		return User{}, err
// 	}
// 	defer res.Body.Close()
//
// 	var user User
// 	decoder := json.NewDecoder(res.Body)
// 	err = decoder.Decode(&user)
// 	if err != nil {
// 		return User{}, err
// 	}
//
// 	return user, nil
// }

package main

import (
	"fmt"
	"net/http"
)

func deleteUser(baseURL, id, apiKey string) error {
	fullURL := baseURL + "/" + id

	// ?
	req, err := http.NewRequest("DELETE", fullURL, nil)
	if err != nil {
		return err
	}
	req.Header.Set("X-API-Key", apiKey)

	client := &http.Client{}
	res, err := client.Do(req)
	if err != nil {
		return err
	}
	defer res.Body.Close()

	if 200 <= res.StatusCode && res.StatusCode <= 299 {
		return nil
	}
	return fmt.Errorf("Error code: ", res.StatusCode)
}
