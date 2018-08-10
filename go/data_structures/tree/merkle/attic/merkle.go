package main

import (
	"bytes"
	"hash"
)

type Node struct {
	Hash  []byte
	Left  *Node
	Right *Node
}

type Proof []map[string][]byte

type Tree struct {
	Hasher hash.Hash
	Blocks []Node // Initial nodes.
	Levels [][]Node
	Nodes  []Node // All nodes.
}

func NewTree(hasher hash.Hash, blocks [][]byte) *Tree {
	return &Tree{
		Hasher: hasher,
		Blocks: addBlocks(hasher, blocks),
	}
}

func addBlocks(hasher hash.Hash, blocks [][]byte) []Node {
	nodes := make([]Node, len(blocks))
	for i, block := range blocks {
		nodes[i] = newNode(hasher, block)
	}
	return nodes
}

func calculateNodeCount(height, blockCount int) int {
	if isPowerOf2(blockCount) {
		return 2*blockCount - 1
	}
	count := blockCount
	for i, lowerLevel := 1, blockCount; i < height; i++ {
		// Always halve the lower level as we proceed up the tree to the top (root).
		lowerLevel = (lowerLevel + (lowerLevel % 2)) / 2
		count += lowerLevel
	}
	return count
}

func calculateTreeHeight(blocks *[]Node) int {
	return log2(nextPowerOf2(len(*blocks))) + 1
}

func hash_(hasher hash.Hash, b []byte) []byte {
	// TODO: Error checking?
	hasher.Write(b)
	defer hasher.Reset()
	return hasher.Sum(nil)
}

func newNode(hasher hash.Hash, b []byte) Node {
	return Node{Hash: hash_(hasher, b)}
}

func (tree *Tree) AddBlocks(blocks [][]byte) {
	tree.Blocks = append(tree.Blocks, addBlocks(tree.Hasher, blocks)...)
}

func (tree *Tree) Generate() {
	blockLength := len(tree.Blocks)

	height := calculateTreeHeight(&tree.Blocks)
	nodeCount := calculateNodeCount(height, blockLength)

	nodes := make([]Node, nodeCount)
	levels := make([][]Node, height)

	// Copy the leaf nodes into the `nodes` collection.
	copy(nodes, tree.Blocks)
	levels[height-1] = tree.Blocks

	current := nodes[blockLength:]
	for i := height - 1; i > 0; i-- {
		below := levels[i]
		linked := tree.GenerateLevelAndLinkNodes(below, current)
		levels[i-1] = current[:linked]
		current = current[linked:]
	}

	tree.Nodes = nodes
	tree.Levels = levels
}

func (tree *Tree) GenerateLevelAndLinkNodes(below []Node, current []Node) int {
	belowLength := len(below)
	numParentNodes := (belowLength + (belowLength % 2)) / 2
	size := tree.Hasher.Size()
	hashes := make([]byte, size*2)

	for i := 0; i < numParentNodes; i++ {
		iLeft := i * 2
		iRight := i*2 + 1
		left := &below[iLeft]
		var right *Node
		node := Node{}

		// TODO: Improve comment!
		// The last time the length will be equal to iRight.
		if belowLength > iRight {
			right = &below[iRight]
			copy(hashes[:size], left.Hash)
			copy(hashes[size:], right.Hash)
			node.Hash = hash_(tree.Hasher, hashes)
		} else {
			leftHash := hashes[:size]
			copy(leftHash, left.Hash)
			node.Hash = leftHash
		}

		node.Left = left
		node.Right = right
		current[i] = node
		hashes = hashes[:]
	}

	return numParentNodes
}

func (tree *Tree) GetLeaf(b []byte) (int, *Node) {
	leafHash := hash_(tree.Hasher, b)
	for i, block := range tree.Blocks {
		if bytes.Equal(block.Hash, leafHash) {
			return i, &block
		}
	}
	return -1, nil
}

func (tree *Tree) GetProof(data interface{}) *Proof {
	var index int

	switch v := data.(type) {
	case []byte:
		index, _ = tree.GetLeaf(v)
	case int:
		index = v
	default:
		index = -1
	}

	if index > -1 {
		idx := index
		proof := Proof{}
		for i := len(tree.Levels) - 1; i > 0; i-- {
			var siblingPosition string
			var siblingIndex int
			nodesLength := len(tree.Levels[i])

			// Is the node the last node in the level?
			// Note that we must check if there is an odd number of nodes in the level!
			if idx == nodesLength-1 && (nodesLength%2 == 1) {
				idx /= 2
				continue
			}

			if idx%2 == 1 {
				siblingPosition = "left"
				siblingIndex = idx - 1
			} else {
				siblingPosition = "right"
				siblingIndex = idx + 1
			}

			proof = append(proof, map[string][]byte{
				siblingPosition: tree.Levels[i][siblingIndex].Hash,
			})

			idx /= 2
		}
		return &proof
	}
	return nil
}

func (tree *Tree) GetRoot() *Node {
	return &tree.Levels[0][0]
}

func (tree *Tree) VerifyProof() {
}

func (tree *Tree) VerifyTree() {
}
