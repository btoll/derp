package main

import "fmt"

var primes = []int{29, 19, 5, 17, 3, 11, 13, 2, 23, 7}

func merge(p, q, r int) {
	i, j, k := 0, 0, p
	lowHalf := make([]int, q-p+1) // Contains q-p+1 elements.
	highHalf := make([]int, r-q)  // Contains r-q elements.

	copy(lowHalf, primes[p:q+1])
	copy(highHalf, primes[q+1:r+1])

	for i < len(lowHalf) && j < len(highHalf) {
		if lowHalf[i] < highHalf[j] {
			primes[k] = lowHalf[i]
			i++
		} else {
			primes[k] = highHalf[j]
			j++
		}
		k++
	}

	for i < len(lowHalf) {
		primes[k] = lowHalf[i]
		i++
		k++
	}

	for j < len(highHalf) {
		primes[k] = highHalf[j]
		j++
		k++
	}
}

func mergeSort(p, r int) {
	if p < r {
		q := (p + r) / 2
		mergeSort(p, q)
		mergeSort(q+1, r)
		merge(p, q, r)
	}
}

func main() {
	fmt.Println(primes)
	mergeSort(0, len(primes)-1)
	fmt.Println(primes)
}
