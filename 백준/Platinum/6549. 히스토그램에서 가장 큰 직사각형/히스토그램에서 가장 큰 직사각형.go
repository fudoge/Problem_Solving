package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	arr []int32
	seg []int32
)

func build(index, l, r int32) {
	if l == r {
		seg[index] = l
		return
	}

	mid := (l + r) / 2
	build(index*2, l, mid)
	build(index*2+1, mid+1, r)
	if arr[seg[index*2]] < arr[seg[index*2+1]] {
		seg[index] = seg[index*2]
	} else {
		seg[index] = seg[index*2+1]
	}
}

func query(index, ql, qr, l, r int32) int32 {
	if ql > r || qr < l {
		return -1
	}
	if ql <= l && r <= qr {
		return seg[index]
	}

	mid := (l + r) / 2
	lq := query(index*2, ql, qr, l, mid)
	rq := query(index*2+1, ql, qr, mid+1, r)
	if lq == -1 && rq == -1 {
		return -1
	}
	if lq == -1 {
		return rq
	}
	if rq == -1 {
		return lq
	}
	if arr[lq] < arr[rq] {
		return lq
	}
	return rq
}

func solve(l, r, n int32) int64 {
	if l > r {
		return 0
	}
	minIdx := query(1, l, r, 1, n)

	currRange := int64(arr[minIdx]) * int64(r-l+1)
	leftRange := solve(l, minIdx-1, n)
	rightRange := solve(minIdx+1, r, n)

	if currRange >= leftRange && currRange >= rightRange {
		return currRange
	} else if leftRange >= currRange && leftRange >= rightRange {
		return leftRange
	} else {
		return rightRange
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int32
	arr = make([]int32, 100001)
	seg = make([]int32, 400004)
	for {
		_, err := fmt.Fscan(reader, &n)
		if err != nil || n == 0 {
			break
		}
		for i := int32(1); i <= n; i++ {
			fmt.Fscan(reader, &arr[i])
		}
		build(1, 1, n)

		fmt.Fprintln(writer, solve(1, n, n))
	}
}