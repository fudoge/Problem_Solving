package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD int64 = 1e9 + 7

var adj [][]int64 = [][]int64{
	{0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 0, 1, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 0, 1, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0},
}

func matMul(a, b [][]int64) [][]int64 {
	c := make([][]int64, 8)

	for i := 0; i < 8; i++ {
		c[i] = make([]int64, 8)
	}

	for i := 0; i < 8; i++ {
		for j := 0; j < 8; j++ {
			for k := 0; k < 8; k++ {
				c[i][j] += a[i][k] * b[k][j]
			}
			c[i][j] %= MOD
		}
	}

	return c
}

func solve(d int32) [][]int64 {
	if d == 1 {
		return adj
	}

	if d%2 == 0 {
		x := solve(d / 2)
		return matMul(x, x)
	}

	return matMul(solve(d-1), adj)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var d int32
	fmt.Fscan(reader, &d)

	res := solve(d)

	fmt.Fprintln(writer, res[0][0])
}