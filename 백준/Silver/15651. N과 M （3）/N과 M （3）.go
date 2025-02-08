package main

import (
	"bufio"
	"fmt"
	"os"
)

var n, m int32
var reader *bufio.Reader
var writer *bufio.Writer

func solve(idx int32, l int32, sl []int32) {
	if l == m {
		for _, v := range sl {
			fmt.Fprintf(writer, "%d ", v)
		}
		fmt.Fprintln(writer)
		return
	}

	for i := idx; i <= n; i++ {
		sl = append(sl, i)
		solve(idx, l+1, sl)
		sl = sl[:len(sl)-1]
	}
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n, &m)
	sl := make([]int32, 1)
	for i := int32(1); i <= n; i++ {
		sl[0] = i
		solve(1, 1, sl)
	}
}