package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int32
	fmt.Fscan(reader, &n, &m)

	adj := make([][]int32, n+1)
	for i := int32(1); i <= n; i++ {
		adj[i] = make([]int32, n+1)
		for j := int32(1); j <= n; j++ {
			adj[i][j] = 100000
		}
		adj[i][i] = 0
	}

	for i := int32(0); i < m; i++ {
		var u, v int32
		fmt.Fscan(reader, &u, &v)
		adj[u][v] = 1
		adj[v][u] = 1
	}

	for k := int32(1); k <= n; k++ {
		for i := int32(1); i <= n; i++ {
			for j := int32(1); j <= n; j++ {
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j])
			}
		}
	}

	ans := int32(0)
	smallest := int32(1e9)
	for i := int32(1); i <= n; i++ {
		x := int32(0)
		for j := int32(1); j <= n; j++ {
			x += adj[i][j]
		}
		if x < smallest {
			ans = i
			smallest = x
		}
	}

	fmt.Fprintln(writer, ans)
}