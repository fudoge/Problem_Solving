package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	n, m    int32
	mat, dp [][]int32
	dx      []int32 = []int32{-1, 1, 0, 0}
	dy      []int32 = []int32{0, 0, -1, 1}
)

func dfs(x, y int32) int32 {
	if x < 0 || y < 0 || x >= n || y >= m {
		return 0
	}
	if x == n-1 && y == m-1 {
		return 1
	}

	if dp[x][y] != -1 {
		return dp[x][y]
	}

	res := int32(0)
	for i := 0; i < 4; i++ {
		nx := x + dx[i]
		ny := y + dy[i]

		if nx >= 0 && nx < n && ny >= 0 && ny < m && mat[x][y] > mat[nx][ny] {
			res += dfs(nx, ny)
		}
	}

	dp[x][y] = res
	return dp[x][y]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n, &m)
	mat = make([][]int32, n)
	dp = make([][]int32, n)
	for i := int32(0); i < n; i++ {
		mat[i] = make([]int32, m)
		dp[i] = make([]int32, m)
		for j := int32(0); j < m; j++ {
			fmt.Fscan(reader, &mat[i][j])
			dp[i][j] = -1
		}
	}

	fmt.Fprintln(writer, dfs(0, 0))
}