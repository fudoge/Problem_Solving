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

	var n, b int64
	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &b)
	b *= n

	var xSum, ySum int64
	for i := int64(0); i < n; i++ {
		var x, y int64
		fmt.Fscan(reader, &x)
		fmt.Fscan(reader, &y)

		xSum += x
		ySum += y
	}

	b -= ySum
	b *= -1

	if xSum == 0 {
		fmt.Fprintln(writer, "EZPZ")
	} else {
		if b%xSum == 0 {
			fmt.Fprintln(writer, b/xSum)
		} else {
			g := gcd(xSum, b)
			b /= g
			xSum /= g
			if xSum < 0 {
				b *= -1
				xSum *= -1
			}
			fmt.Fprintf(writer, "%d/%d\n", b, xSum)
		}
	}
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
