package main

import (
	"crypto/sha256"
	"fmt"
)

func Test() {
	sha := sha256.New()

	fmt.Println()
	sha.Reset()
	sha.Write([]byte("Huck"))
	huck := sha.Sum(nil)
	fmt.Println("Huck\t\t", huck)

	sha.Reset()
	sha.Write([]byte("Utley"))
	utley := sha.Sum(nil)
	fmt.Println("Utley\t\t", utley)

	sha.Reset()
	sha.Write([]byte("Molly"))
	molly := sha.Sum(nil)
	fmt.Println("Molly\t\t", molly)

	sha.Reset()
	sha.Write([]byte("Pete"))
	pete := sha.Sum(nil)
	fmt.Println("Pete\t\t", pete)

	sha.Reset()
	hashed := make([]byte, sha.Size()*2)
	copy(hashed[:sha.Size()], huck)
	copy(hashed[sha.Size():], utley)
	sha.Write(hashed)
	huckutley := sha.Sum(nil)
	fmt.Println("Huck/Utley\t", huckutley)

	sha.Reset()
	hashed = hashed[:]
	copy(hashed[:sha.Size()], huckutley)
	copy(hashed[sha.Size():], molly)
	sha.Write(hashed)
	root := sha.Sum(nil)
	fmt.Println("Merkle root\t", root)
	fmt.Println()
}
