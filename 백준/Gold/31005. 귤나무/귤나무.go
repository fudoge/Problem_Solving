package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int64
	fmt.Fscan(reader, &n, &m)

	curr := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(reader, &curr[i])
	}

	for {
		pref := make([]int64, len(curr)+1)
		for i := 1; i <= len(curr); i++ {
			pref[i] = pref[i-1] + curr[i-1]
		}

		m = m % pref[len(curr)]

		next := make([]int64, 0)
		for _, a := range curr {
			if a <= m {
				m -= a
				next = append(next, a)
			}
		}

		if len(next) == 0 {
			break
		}

		curr = next
	}

	fmt.Fprintln(writer, m)

}
