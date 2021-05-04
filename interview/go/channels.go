package main

import (
	"time"
)

timerChan := make(chan time.Time)
go func() {
	time.Sleep(deltaT)
	timerChan <- time.Now() // send time on timerChan
}()
// Do something else; when ready, receive.
// Receive will block until timerChan delivers.
// Value sent is other goroutine's completion time.
completedAt := <-timerChan
