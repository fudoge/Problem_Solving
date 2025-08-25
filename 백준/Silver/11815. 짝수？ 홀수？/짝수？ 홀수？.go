package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	for i := 0; i < n; i++ {
		var temp int
		fmt.Fscanf(reader, "%d", &temp)
		r := int(math.Sqrt(float64(temp)))

		r2 := r * r
		if r2 == temp {
			fmt.Fprintf(writer, "1 ")
		} else {
			fmt.Fprintf(writer, "0 ")
		}
	}

	fmt.Fprintln(writer)
}
