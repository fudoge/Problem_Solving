package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a, b int32) int32 {
	if a > b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int32
	fmt.Fscan(reader, &n)
	a := make([]int32, n)
	b := make([]int32, n)
	h := int32(-1)
	l := int32(1)
	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}
	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &b[i])
		h = max(h, (a[i]+b[i]-1)/b[i])
	}

	for l < h {
		mid := (l + h) / 2
		flag := true
		extra := int32(0)
		for i := int32(0); i < n; i++ {
			fin := (a[i] + b[i] - 1) / b[i]
			if fin > mid {
				extra += fin - mid
				if extra > mid {
					flag = false
					break
				}
			}
		}
		if flag {
			h = mid
		} else {
			l = mid + 1
		}
	}

	fmt.Fprintln(writer, l)
}
