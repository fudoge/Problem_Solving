package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func getRoot(x int32, parent []int32) int32 {
	if parent[x] == x {
		return x
	}
	parent[x] = getRoot(parent[x], parent)
	return parent[x]
}

func lowerBound(cards []int32, target int32) int32 {
	l, r := int32(0), int32(len(cards))
	for l < r {
		mid := l + (r-l)/2
		if cards[mid] < target {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, k int32
	fmt.Fscan(reader, &n, &m, &k)

	cards := make([]int32, m)
	for i := int32(0); i < m; i++ {
		fmt.Fscan(reader, &cards[i])
	}
	sort.Slice(cards, func(i, j int) bool { return cards[i] < cards[j] })

	parent := make([]int32, m+1)
	for i := int32(0); i <= m; i++ {
		parent[i] = i
	}

	for i := int32(0); i < k; i++ {
		var opponentCard int32
		fmt.Fscan(reader, &opponentCard)
		targetValue := opponentCard + 1

		candidate := lowerBound(cards, targetValue)
		candidate = getRoot(candidate, parent)

		fmt.Fprintln(writer, cards[candidate])
		parent[candidate] = getRoot(candidate+1, parent)
	}
}