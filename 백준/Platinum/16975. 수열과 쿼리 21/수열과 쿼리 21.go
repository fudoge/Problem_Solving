package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	a, seg, lazy []int64
)

func build(index, l, r int32) {
	if l == r {
		seg[index] = a[l]
		return
	}

	mid := (l + r) >> 1
	build(index*2+1, l, mid)
	build(index*2+2, mid+1, r)
	seg[index] = seg[index*2+1] + seg[index*2+2]
}

func propagate(index, l, r int32) {
	if lazy[index] != 0 {
		seg[index] += lazy[index] * int64(r-l+1)
		if l != r {
			lazy[index*2+1] += lazy[index]
			lazy[index*2+2] += lazy[index]
		}
		lazy[index] = 0
	}
}

func rangeUpdate(index, l, r, ql, qr, inc int32) {
	propagate(index, l, r)
	if ql > r || qr < l {
		return
	}

	if ql <= l && r <= qr {
		lazy[index] += int64(inc)
		propagate(index, l, r)
		return
	}

	mid := (l + r) >> 1
	rangeUpdate(index*2+1, l, mid, ql, qr, inc)
	rangeUpdate(index*2+2, mid+1, r, ql, qr, inc)
	seg[index] = seg[index*2+1] + seg[index*2+2]
}

func query(index, l, r, target int32) int64 {
	propagate(index, l, r)
	if l == r {
		return seg[index]
	}
	mid := (l + r) >> 1
	if target <= mid {
		return query(index*2+1, l, mid, target)
	} else {
		return query(index*2+2, mid+1, r, target)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int32
	fmt.Fscan(reader, &n)
	a = make([]int64, n)
	seg = make([]int64, 4*n)
	lazy = make([]int64, 4*n)

	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}
	fmt.Fscan(reader, &m)

	build(0, 0, n-1)

	for i := int32(0); i < m; i++ {
		var cmd int32
		fmt.Fscan(reader, &cmd)
		if cmd == 1 {
			var ql, qr, k int32
			fmt.Fscan(reader, &ql, &qr, &k)
			rangeUpdate(0, 0, n-1, ql-1, qr-1, k)
		} else {
			var x int32
			fmt.Fscan(reader, &x)
			fmt.Fprintln(writer, query(0, 0, n-1, x-1))
		}
	}
}