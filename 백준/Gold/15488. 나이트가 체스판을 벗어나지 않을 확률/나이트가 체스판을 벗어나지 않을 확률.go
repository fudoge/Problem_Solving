package main

import (
	"bufio"
	"fmt"
	"os"
)

var moves [][]int = [][]int{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}}
var reader *bufio.Reader
var writer *bufio.Writer
var n int

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var x, y, k int
	fmt.Fscan(reader, &n, &x, &y, &k)

	dp := make([][][]float64, n+1)
	for i := 0; i < n; i++ {
		dp[i] = make([][]float64, n+1)
		for j := 0; j < n; j++ {
			dp[i][j] = make([]float64, k+1)
			for l := 0; l <= k; l++ {
				dp[i][j][l] = -1.0
			}
		}
	}
	ans := solve(x-1, y-1, k, dp)

	fmt.Fprintln(writer, ans)
}

func solve(x, y, k int, dp [][][]float64) float64 {
	if x < 0 || y < 0 || x >= n || y >= n {
		return 0
	}
	if k == 0 {
		return 1
	}
	if dp[x][y][k] != -1.0 {
		return dp[x][y][k]
	}

	res := 0.0
	for _, d := range moves {
		dx := d[0]
		dy := d[1]

		nx := x + dx
		ny := y + dy

		res += solve(nx, ny, k-1, dp) / 8
	}
	dp[x][y][k] = res
	return res
}
