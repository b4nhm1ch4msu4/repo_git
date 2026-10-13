package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
)

func getIPAddress(domain string) (string, error) {
	url := fmt.Sprintf("https://dns.google/resolve?name=%s&type=A", domain)

	req, err := http.NewRequest("GET", url, nil)
	if err != nil {
		return "", fmt.Errorf("error creating request: %w", err)
	}
	req.Header.Set("accept", "application/dns-json")

	client := http.Client{}
	res, err := client.Do(req)
	if err != nil {
		return "", fmt.Errorf("error sending request: %w", err)
	}
	defer res.Body.Close()

	body, err := io.ReadAll(res.Body)
	if err != nil {
		return "", fmt.Errorf("error reading response body: %w", err)
	}
	var dns_obj DNSResponse

	json.Unmarshal(body, &dns_obj)
	if len(dns_obj.Answer) == 0 {
		return "", fmt.Errorf("Empty IP")
	}
	ip := dns_obj.Answer[0].Data
	return ip, nil
}

// func main() {
// 	ip, err := getIPAddress("google.com")
// 	if err != nil {
// 		fmt.Print(err)
// 	} else {
// 		fmt.Printf(ip)
// 	}
// }
