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

// package main
//
// type contact struct {
// 	sendingLimit int32
// 	age          int32
// 	userID       string
// }
//
// type perms struct {
// 	permissionLevel int
// 	canSend         bool
// 	canReceive      bool
// 	canManage       bool
// }

// package main
//
// type User struct {
// 	Name string
// 	Membership
// }
//
// type Membership struct {
// 	Type             string
// 	MessageCharLimit int
// }
//
// func newUser(name string, membershipType string) User {
// 	// ?
// 	if membershipType == "premium" {
// 		return User{Name: name,
// 			Membership: Membership{
// 				Type:             membershipType,
// 				MessageCharLimit: 1000,
// 			},
// 		}
// 	} else {
// 		return User{Name: name,
// 			Membership: Membership{
// 				Type:             membershipType,
// 				MessageCharLimit: 100,
// 			},
// 		}
// 	}
// }

package main

// ?
func (u User) SendMessage(message string, messageLength int) (string, bool) {
	if messageLength <= u.MessageCharLimit {
		return message, true
	} else {
		return "", false
	}
}

// don't touch below this line

type User struct {
	Name string
	Membership
}

type Membership struct {
	Type             string
	MessageCharLimit int
}

func newUser(name string, membershipType string) User {
	membership := Membership{Type: membershipType}
	if membershipType == "premium" {
		membership.MessageCharLimit = 1000
	} else {
		membership.Type = "standard"
		membership.MessageCharLimit = 100
	}
	return User{Name: name, Membership: membership}
}
