package main

func main() {
	c := make(chan int, 5)
	c <- 5
	c <- 6
	close(c)
	println(<-c)
}
