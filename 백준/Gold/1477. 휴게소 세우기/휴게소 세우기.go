package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func check(interval, m, l int32, arr []int32) bool {
	last := int32(0)
	cnt := m
	for i := 0; i < len(arr); i++ {
		for last+interval < arr[i] {
			cnt--
			if cnt < 0 {
				return false
			}
			last += interval
		}
		last = max(last, arr[i])
	}

	for last+interval < l {
		cnt--
		if cnt < 0 {
			return false
		}
		last += interval
	}

	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, l int32
	fmt.Fscan(reader, &n, &m, &l)

	arr := make([]int32, n)
	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	lo := int32(1)
	hi := l
	ans := int32(0)

	for lo <= hi {
		mid := (lo + hi) >> 1
		if check(mid, m, l, arr) {
			ans = mid
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}
	fmt.Fprintln(writer, ans)
}