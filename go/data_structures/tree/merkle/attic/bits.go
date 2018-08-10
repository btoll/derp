package main

func isPowerOf2(n int) bool {
	return n > 0 && (n&(n-1) == 0)
}

func log2(n int) int {
	i := n
	c := 0
	for i > 0 {
		i >>= 1
		c++
	}
	return c - 1
}

func nextPowerOf2(n int) int {
	i := n
	i--
	i |= i >> 1
	i |= i >> 2
	i |= i >> 4
	i |= i >> 8
	i |= i >> 16
	i |= i >> 32
	i++
	return i
}
