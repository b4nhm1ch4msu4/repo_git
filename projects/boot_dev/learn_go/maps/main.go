package main

func updateCounts(messagedUsers []string, validUsers map[string]int) {
	// ?
	for _, e := range messagedUsers {
		if _, ok := validUsers[e]; ok {
			validUsers[e] += 1
		}
	}
}
