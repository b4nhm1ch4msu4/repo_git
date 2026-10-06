// package main
//
// import "fmt"
//
// func (a *analytics) handleEmailBounce(em email) error {
// 	u_err := em.recipient.updateStatus(em.status)
// 	if u_err != nil {
// 		return fmt.Errorf("error updating user status: %w", u_err)
// 	}
// 	t_err := a.track(em.status)
// 	if t_err != nil {
// 		return fmt.Errorf("error tracking user bounce: %w", t_err)
// 	}
// 	return nil
// }
//

package main

type emailStatus int

const (
	EmailBounced emailStatus = iota
	EmailInvalid
	EmailDelivered
	EmailOpened
)
