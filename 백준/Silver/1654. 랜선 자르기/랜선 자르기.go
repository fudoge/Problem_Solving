package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var k, n int64
	fmt.Fscan(reader, &k, &n)
	lo := int64(1)
	hi := int64(1)
	arr := make([]int64, k)
	for i := int64(0); i < k; i++ {
		fmt.Fscan(reader, &arr[i])
		hi = max(hi, arr[i])
	}

	for lo <= hi {
		mid := (lo + hi) / 2
		cnt := int64(0)
		for _, v := range arr {
			cnt += v / mid
		}
		if cnt >= n {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}

	fmt.Fprintln(writer, lo-1)
}