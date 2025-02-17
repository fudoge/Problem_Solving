package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, c int32
	fmt.Fscan(reader, &n, &c)
	arr := make([]int32, n)
	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	lo := int32(1)
	hi := int32(arr[n-1] - arr[0])
	for lo <= hi {
		mid := (lo + hi) / 2
		flag := false
		last := int32(arr[0])
		cnt := int32(1)
		for i := int32(1); i < n; i++ {
			if arr[i]-last >= mid {
				last = arr[i]
				cnt++
				if cnt == c {
					flag = true
					break
				}
			}
		}
		if flag {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}

	fmt.Fprintln(writer, lo-1)
}