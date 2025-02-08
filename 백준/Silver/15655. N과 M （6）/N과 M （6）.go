package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var n, m int32
var reader *bufio.Reader
var writer *bufio.Writer
var arr []int32

func solve(idx int32, sl []int32) {
	if int32(len(sl)) == m {
		for _, v := range sl {
			fmt.Fprintf(writer, "%d ", v)
		}
		fmt.Fprintln(writer)
		return
	}

	if idx >= n {
		return
	}

	sl = append(sl, arr[idx])
	solve(idx+1, sl)
	sl = sl[:len(sl)-1]
	solve(idx+1, sl)
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n, &m)
	arr = make([]int32, n)
	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	sl := make([]int32, 0)
	solve(0, sl)
}