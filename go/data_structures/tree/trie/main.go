package main

import "fmt"

type Node struct {
	Children map[rune]*Node
	Value    string
}

func find(node *Node, s string) bool {
	for _, char := range s {
		if _, ok := node.Children[char]; ok {
			node = node.Children[char]
		} else {
			return false
		}
	}
	return true
}

func insert(root *Node, s string) *Node {
	node := root
	lastIndex := 0
	for i, char := range s {
		if _, ok := node.Children[char]; ok {
			node = node.Children[char]
		} else {
			lastIndex = i
			break
		}
	}

	for _, char := range s[lastIndex:] {
		node.Children[char] = &Node{
			Children: make(map[rune]*Node),
		}
		node = node.Children[char]
	}

	// Store value in the terminal node.
	node.Value = s

	return node
}

func main() {
	str := "utley"
	trie := &Node{
		Children: make(map[rune]*Node),
		Value:    "",
	}

	fmt.Println("contains string?", find(trie, str))
	insert(trie, str)
	fmt.Println("contains string?", find(trie, str))
}
