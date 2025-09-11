package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscan(reader, &t)
	for ; t > 0; t-- {
		solve()
	}
}

func solve() {
	var n int
	fmt.Fscan(reader, &n)

	parent := make([]int, n+1)
	dist := make([]int, n+1)
	for i := 1; i <= n; i++ {
		parent[i] = i
		dist[i] = 0
	}

	for {
		var cmd string
		fmt.Fscan(reader, &cmd)
		c := cmd[0]

		if c == 'O' {
			break
		}
		if c == 'E' {
			var I int
			fmt.Fscan(reader, &I)
			find(I, parent, dist)
			fmt.Fprintln(writer, dist[I])
		} else {
			var I, J int
			fmt.Fscan(reader, &I, &J)
			parent[I] = J
			d := I - J
			if d < 0 {
				d = -d
			}
			dist[I] = d % 1000
		}
	}
}

func find(x int, parent, dist []int) int {
	if x == parent[x] {
		return x
	}

	p := parent[x]
	root := find(p, parent, dist)
	dist[x] += dist[p]
	parent[x] = root
	return root
}
