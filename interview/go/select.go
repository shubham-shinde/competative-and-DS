package main

import (
	"fmt"
	"time"
)

func main() {
	c1 := make(chan string)
	c2 := make(chan string)
	go func() {
		for {
			c1 <- "Every 500ms"
			time.Sleep(time.Millisecond * 500)
		}
	}()

	go func() {
		for {
			c2 <- "Every 2 sec"
			time.Sleep(time.Second * 2)
		}
	}()
	// if you user below code
	// for {
	// 	fmt.Println(<-c1)
	// 	fmt.Println(<-c2)
	// }
	// this will print 500 and 2 sec in 2 sec
	// as c2 will wait for c1 to listen
	for {
		select {
		case msg1 := <- c1:
			fmt.Println(msg1)
		case msg2 := <- c2:
			fmt.Println(msg2)
		}
	}
	// using select prgoram will wait for both response
}
