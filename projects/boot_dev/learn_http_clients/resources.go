package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"sort"
)

func getResources(url string) ([]map[string]any, error) {
	var resources []map[string]any

	res, err := http.Get(url)
	if err != nil {
		return resources, err
	}

	defer res.Body.Close()

	// ?
	data, err := io.ReadAll(res.Body)
	if err != nil {
		return nil, err
	}
	json.Unmarshal(data, &resources)
	return resources, nil
}

func logResources(resources []map[string]any) {
	var formattedStrings []string

	// ?
	for _, i := range resources {
		for k, v := range i {
			new_string := fmt.Sprintf("Key: %s - Value: %v", k, v)
			formattedStrings = append(formattedStrings, new_string)
		}
	}

	sort.Strings(formattedStrings)

	for _, str := range formattedStrings {
		fmt.Println(str)
	}
}
