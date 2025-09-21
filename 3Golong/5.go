package main

import (
	"fmt"
	"math/rand"
	"time"
)

var someNumber int

func main() {
	someNumber = 0
	totalIterations := 0

	turnA := make(chan bool, 1)
	turnB := make(chan bool, 1)

	turnB <- true

	go func() {
		for {
			<-turnA
			someNumber -= 1
			fmt.Println("someNumber =", someNumber)

			if someNumber >= 100 {
				fmt.Println("Total iterations: ", totalIterations)
				break
			}

			turnB <- true
			time.Sleep(3 * time.Millisecond)
		}
	}()

	go func() {
		for {
			<-turnB
			someNumber += 2
			totalIterations += 1
			//fmt.Println("someNumber =", someNumber)
			time.Sleep(time.Duration(rand.Intn(5)) * time.Millisecond)

			turnA <- true
		}
	}()

	time.Sleep(10 * time.Second)
}
