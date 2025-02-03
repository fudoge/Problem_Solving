package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int32
var m int32
var reader *bufio.Reader
var writer *bufio.Writer

func solve(last int32, visited []bool, arr []int32) {
	if int32(len(arr)) == m {
		for _, v := range arr {
			fmt.Fprint(writer, v)
			fmt.Fprint(writer, " ")
		}
		fmt.Fprintln(writer)
		return
	}

	for i := int32(last)+1; i <= n; i++ {
		if visited[i] == false {
			visited[i] = true
			arr = append(arr, i)
			solve(i, visited, arr)
			visited[i] = false
			arr = arr[:len(arr)-1]
		}
	}
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &m)

	arr := make([]int32, 0)
	visited := make([]bool, n+1)
	for i := int32(1); i <= n; i++ {
		visited[i] = true
		arr = append(arr, i)
		solve(i, visited, arr)
		visited[i] = false
		arr = arr[:len(arr)-1]
	}
}