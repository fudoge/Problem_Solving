package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var (
	arr    []int32
	minSeg []int32
	maxSeg []int32
)

func min(a, b int32) int32 {
	if a > b {
		return b
	}
	return a
}

func max(a, b int32) int32 {
	if a < b {
		return b
	}
	return a
}

func build(index, l, r int32) {
	if l == r {
		minSeg[index] = arr[l]
		maxSeg[index] = arr[r]
		return
	}

	mid := (l + r) / 2
	build(index*2, l, mid)
	build(index*2+1, mid+1, r)
	minSeg[index] = min(minSeg[index*2], minSeg[index*2+1])
	maxSeg[index] = max(maxSeg[index*2], maxSeg[index*2+1])
}

func query(index, ql, qr, l, r int32) (int32, int32) {
	if ql > r || qr < l {
		return math.MaxInt32, math.MinInt32
	}

	if ql <= l && r <= qr {
		return minSeg[index], maxSeg[index]
	}

	mid := (l + r) / 2
	lmin, lmax := query(index*2, ql, qr, l, mid)
	rmin, rmax := query(index*2+1, ql, qr, mid+1, r)

	return min(lmin, rmin), max(rmax, lmax)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int32
	fmt.Fscan(reader, &n, &m)
	arr = make([]int32, n+1)
	minSeg = make([]int32, 4*(n+1))
	maxSeg = make([]int32, 4*(n+1))

	for i := int32(1); i <= n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	build(1, 1, n)

	for i := int32(0); i < m; i++ {
		var a, b int32
		fmt.Fscan(reader, &a, &b)
		minima, maxima := query(1, a, b, 1, n)

		fmt.Fprintln(writer, minima, maxima)
	}
}