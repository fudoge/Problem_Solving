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
		sum := int64(0)
		for i := 0; i < len(curr); i++ {
			sum += curr[i]
		}

		m = m % sum

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
