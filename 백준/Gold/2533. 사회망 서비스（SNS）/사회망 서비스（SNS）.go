package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	n   int32
	adj [][]int32
	dp  [][]int32
)

func dfs(parent, node int32) {
	dp[node][0] = 0
	dp[node][1] = 1
	if len(adj[node]) == 1 && adj[node][0] == parent {
		return
	}

	for _, child := range adj[node] {
		if child == parent {
			continue
		}

		dfs(node, child)
		dp[node][0] += dp[child][1]
		dp[node][1] += min(dp[child][0], dp[child][1])
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n)
	adj = make([][]int32, n+1)
	dp = make([][]int32, n+1)
	for i := int32(0); i <= n; i++ {
		adj[i] = make([]int32, 0)
		dp[i] = []int32{-1, -1}
	}
	for i := int32(1); i < n; i++ {
		var u, v int32
		fmt.Fscan(reader, &u, &v)
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	dfs(0, 1)

	fmt.Fprintln(writer, min(dp[1][0], dp[1][1]))
}