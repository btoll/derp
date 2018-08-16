package main

import "fmt"

var primes = []int{29, 19, 5, 17, 3, 11, 13, 2, 23, 7}

func swap(first, second int) {
	// Obviously, don't do the swap if it's the same index!
	if first != second {
		primes[first] ^= primes[second]
		primes[second] = primes[first] ^ primes[second]
		primes[first] ^= primes[second]
	}
}

func partition(p, r int) int {
	q, j, pivot := p, p, primes[r]
	for j < r {
		if primes[j] <= pivot {
			swap(q, j)
			q++
		}
		j++
	}
	swap(q, r)
	return q
}

func quickSort(p, r int) {
	if p < r {
		q := partition(p, r)
		quickSort(p, q-1)
		quickSort(q+1, r)
	}
}

func main() {
	fmt.Println(primes)
	quickSort(0, len(primes)-1)
	fmt.Println(primes)
}
