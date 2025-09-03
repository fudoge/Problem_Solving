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

	var a, b int64
	fmt.Fscan(reader, &a, &b)

	ans := getXORSum(b) ^ getXORSum(a-1)
	fmt.Fprintln(writer, ans)
}

func getXORSum(n int64) int64 {
	mod := n % 4
	if mod == 0 {
		return n
	} else if mod == 1 {
		return 1
	} else if mod == 2 {
		return n + 1
	} else {
		return 0
	}
}
