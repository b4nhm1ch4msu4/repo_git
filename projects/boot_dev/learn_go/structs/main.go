// package main
//
// type messageToSend struct {
// 	phoneNumber		int
// 	message				string
// }

// package main
//
// type messageToSend struct {
// 	message   string
// 	sender    user
// 	recipient user
// }
//
// type user struct {
// 	name   string
// 	number int
// }
//
// func canSendMessage(mToSend messageToSend) bool {
// 	// ?
// 	if mToSend.sender.name == "" || mToSend.sender.number == 0 || mToSend.recipient.name == "" || mToSend.recipient.number == 0 {
// 		return false
// 	}
// 	return true
// }

// package main
//
// type sender struct {
// 	user
// 	rateLimit int
// }
//
// type user struct {
// 	name   string
// 	number int
// }

// package main
//
// import "fmt"
//
// type authenticationInfo struct {
// 	username string
// 	password string
// }
//
// func (i authenticationInfo) getBasicAuth() string {
// 	return fmt.Sprintf("Authorization: Basic %s:%s", i.username, i.password)
// }


package main

type contact struct {
	sendingLimit int32
	age          int32
	userID       string
}

type perms struct {
	permissionLevel int
	canSend         bool
	canReceive      bool
	canManage       bool
}
