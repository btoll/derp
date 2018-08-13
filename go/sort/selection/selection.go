package main

import "fmt"

var primes = []int{29, 19, 5, 17, 3, 11, 13, 2, 23, 7}

func swap(first, second int) {
	primes[first] ^= primes[second]
	primes[second] = primes[first] ^ primes[second]
	primes[first] ^= primes[second]
}

func selectionSort() {
	for i := 0; i < len(primes); i++ {
		for j := i + 1; j < len(primes); j++ {
			if primes[j] < primes[i] {
				swap(i, j)
			}
		}
	}
}

func main() {
	fmt.Println(primes)
	selectionSort()
	fmt.Println(primes)
}
