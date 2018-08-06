package main

import (
	"fmt"
)

//
// Balanced Binary Tree
//
//              __ 100 __
//             /         \
//         50              150
//       /    \          /     \
//     25      75      125     175
//                   /
//                 110
//
//
//
//  Preorder traversal of the BST where the result is:  { 100, 50, 25, 75, 150, 125, 110, 175 }
//   Inorder traversal of the BST where the result is:  { 25, 50, 75, 100, 110, 125, 150, 175 }
// Postorder traversal of the BST where the result is:  { 25, 75, 50, 110, 125, 175, 150, 100 }
//

type Node struct {
	Left  *Node
	Right *Node
	Value int
}

func newNode(v int) *Node {
	return &Node{nil, nil, v}
}

func addNode(v int, node *Node) *Node {
	if v <= node.Value {
		if node.Left == nil {
			node.Left = newNode(v)
			return node.Left
		} else {
			return addNode(v, node.Left)
		}
	}
	if v > node.Value {
		if node.Right == nil {
			node.Right = newNode(v)
			return node.Right
		} else {
			return addNode(v, node.Right)
		}
	}
	return nil
}

func inOrderTraversal(node *Node) {
	if node.Left != nil {
		inOrderTraversal(node.Left)
	}
	fmt.Println(node.Value)
	if node.Right != nil {
		inOrderTraversal(node.Right)
	}
}

func preOrderTraversal(node *Node) {
	fmt.Println(node.Value)
	if node.Left != nil {
		preOrderTraversal(node.Left)
	}
	if node.Right != nil {
		preOrderTraversal(node.Right)
	}
}

func postOrderTraversal(node *Node) {
	if node.Left != nil {
		postOrderTraversal(node.Left)
	}
	if node.Right != nil {
		postOrderTraversal(node.Right)
	}
	fmt.Println(node.Value)
}

func main() {
	root := newNode(100)
	addNode(150, root)
	addNode(125, root)
	addNode(50, root)
	addNode(175, root)
	addNode(75, root)
	addNode(25, root)
	addNode(110, root)

	fmt.Println("preorder")
	preOrderTraversal(root)
	fmt.Println("")

	fmt.Println("inorder")
	inOrderTraversal(root)
	fmt.Println("")

	fmt.Println("postorder")
	postOrderTraversal(root)
	fmt.Println("")
}
