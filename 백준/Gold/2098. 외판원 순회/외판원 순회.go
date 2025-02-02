package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int32
var adj [][]int32
var dp [][]int32

func solve(last, state int32) int32 {
	if state == (1<<n)-1 {
		if adj[last][0] == 0 {
			return int32(1e9)
		}
		return adj[last][0]
	}

	if dp[state][last] != -1 {
		return dp[state][last]
	}

	res := int32(1e9)
	var i int32

	for i = 0; i < n; i++ {
		if state&(1<<i) == 0 && adj[last][i] != 0 {
			rres := solve(i, state|(1<<i)) + adj[last][i]
			if rres < res {
				res = rres
			}
		}
	}

	dp[state][last] = res
	return dp[state][last]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n)
	adj = make([][]int32, n)
	dp = make([][]int32, (1 << n))

	var i int32
	var j int32

	for i = 0; i < n; i++ {
		adj[i] = make([]int32, n)
	}

	for i = 0; i < (1 << n); i++ {
		dp[i] = make([]int32, n)
		for j = 0; j < n; j++ {
			dp[i][j] = -1
		}
	}

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Fscan(reader, &adj[i][j])
		}
	}

	fmt.Fprintln(writer, solve(0, 1))
}