package main

import (
	"crypto/sha256"
	"fmt"

	"github.com/btoll/merkle-tree"
)

func main() {
	tree, err := merkle.New(sha256.New(), [][]byte{
		[]byte("Huck"),
		[]byte("Utley"),
		[]byte("Molly"),
		[]byte("Pete"),
		//[]byte("Lily"),
		//		[]byte("Rupert"),
		//		[]byte("Little Noam"),
	})

	err = tree.GenerateTree()
	if err != nil {
		fmt.Println(err)
	}

	//	fmt.Println("Merkle root", fmt.Sprintf("%x", tree.GetRoot().Hash))
	fmt.Println("Merkle root", tree.GetRoot().Hash)
	//	fmt.Println("", tree.Leaves[0].Parent.Parent)
	//	fmt.Println("tree.Leaves[0]", tree.Leaves[0])
	//	fmt.Println("tree.Levels[2][0]", tree.Levels[2][0])
	//	fmt.Println("tree.Levels[2][1]", tree.Levels[2][1])
	//	fmt.Println("tree.Levels[1][0]", tree.Levels[1][0])
	//	fmt.Println("tree.Levels[0][0]", tree.Levels[0][0])
	fmt.Println("tree.VerifyNode(tree.Levels[1][1])", tree.VerifyNode(tree.Levels[1][1]))
	fmt.Println("tree.VerifyTree()", tree.VerifyTree())
}
