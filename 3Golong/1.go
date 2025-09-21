package main

import "fmt"

func main() {
	fmt.Println(add([]int{1, 2, 3}...))
}

func add(args ...int) int {
	sum := 0
	for _, arg := range args {
		sum += arg
	}
	return sum
}
