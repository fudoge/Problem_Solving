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

	var n, k int32
	fmt.Fscan(reader, &n, &k)

	lo := int32(1)
	hi := k
	var ans int32
	for lo <= hi {
		mid := (lo + hi) / 2
		cnt := int32(0)
		for i := int32(1); i <= n; i++ {
			cnt += min(n, mid/i)
		}

		if cnt >= k {
			ans = mid
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}

	fmt.Fprintln(writer, ans)

}