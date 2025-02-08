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

func solve(sl []int32) {
	if int32(len(sl)) == m {
		for _, v := range sl {
			fmt.Fprintf(writer, "%d ", v)
		}
		fmt.Fprintln(writer)
		return
	}

	for i := int32(0); i < n; i++ {
		sl = append(sl, arr[i])
		solve(sl)
		sl = sl[:len(sl)-1]
	}
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n, &m)
	arr = make([]int32, n)
	sl := make([]int32, 1)
	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})
	for i := int32(0); i < n; i++ {
		sl[0] = arr[i]
		solve(sl)
	}
}