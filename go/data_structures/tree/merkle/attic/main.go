package main

import (
	"crypto/sha256"
	"fmt"
)

func main() {
	tree := NewTree(sha256.New(), [][]byte{
		[]byte("Huck"),
		[]byte("Utley"),
		[]byte("Molly"),
		[]byte("Pete"),
		//		[]byte("Lily"),
		//		[]byte("Roo"),
		//		[]byte("Moose"),
		//		[]byte("Annie"),
		//		[]byte("Phoebe"),
		//		[]byte("Chomsky"),
		//		[]byte("Little Noam"),
	})

	tree.Generate()
	fmt.Println("Merkle root node\t", tree.GetRoot())
	index, node := tree.GetLeaf([]byte("Molly"))
	fmt.Println("Leaf node\t\t", index, node)

	// Can get proof by either value (byte array) or integer (index).
	//	proof := tree.GetProof([]byte("Molly"))
	proof := tree.GetProof(index)

	if proof != nil {
		for _, p := range *proof {
			fmt.Println("GetProof(\"Molly\")\t", p)
		}
	}
	//	Test()
}
