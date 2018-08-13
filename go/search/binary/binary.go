package main

import (
	"fmt"
	"os"
	"strconv"
)

var primes = []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}

func non_recursive_int(n int) int {
	max, min := len(primes)-1, 0

	for min <= max {
		mid := (max + min) / 2
		if n == primes[mid] {
			return mid
		}
		if n > primes[mid] {
			min = mid + 1
		} else {
			max = mid - 1
		}
	}
	return -1
}

func recursive_int(n, max, min int) int {
	if max < min {
		return -1
	}

	mid := (max + min) / 2

	if n == primes[mid] {
		return mid
	}

	if n > primes[mid] {
		min = mid + 1
	} else {
		max = mid - 1
	}

	return recursive_int(n, max, min)
}

// Still getting an off-bye-one error when a number is in bounds but not in the slice!
func recursive_slice(a []int, n int) bool {
	if len(a) == 0 {
		return false
	}

	mid := len(a) / 2

	if n == a[mid] {
		return true
	}

	if n < a[mid] {
		a = a[:mid]
	} else {
		a = a[mid:]
	}

	return recursive_slice(a, n)
}

func main() {
	if len(os.Args) == 1 {
		fmt.Println("You must provide an integer argument to search for!")
		return
	}
	n, _ := strconv.Atoi(os.Args[1])

	fmt.Println(non_recursive_int(n))
	fmt.Println(recursive_int(n, len(primes)-1, 0))
	fmt.Println(recursive_slice(primes, n))
}
