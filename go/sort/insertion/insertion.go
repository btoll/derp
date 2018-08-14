package main

import "fmt"

var primes = []int{29, 19, 5, 17, 3, 11, 13, 2, 23, 7}

func moveAndInsert(rightIndex, key int) {
	i := rightIndex
	for primes[i] > key {
		primes[i+1] = primes[i]
		i--
		if i < 0 {
			break
		}
	}
	primes[i+1] = key
}

func insertionSort() {
	for i := 1; i < len(primes); i++ {
		moveAndInsert(i-1, primes[i])
	}
}

func main() {
	fmt.Println("primes ", primes)
	insertionSort()
	fmt.Println("primes ", primes)
}
