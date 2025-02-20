package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	arr  []int64
	seg  []int64
	lazy []int64
)

func build(index, l, r int32) {
	if l == r {
		seg[index] = arr[l]
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

func update(index, l, r, ql, qr int32, val int64) {
	propagate(index, l, r)
	if l > qr || r < ql {
		return
	}

	if ql <= l && r <= qr {
		lazy[index] += val
		propagate(index, l, r)
		return
	}

	mid := (l + r) >> 1
	update(index*2+1, l, mid, ql, qr, val)
	update(index*2+2, mid+1, r, ql, qr, val)
	seg[index] = seg[index*2+1] + seg[index*2+2]
}

func query(index, l, r, ql, qr int32) int64 {
	propagate(index, l, r)
	if l > qr || r < ql {
		return 0
	}

	if ql <= l && r <= qr {
		return seg[index]
	}

	mid := (l + r) >> 1
	lres := query(index*2+1, l, mid, ql, qr)
	rres := query(index*2+2, mid+1, r, ql, qr)
	return lres + rres
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, k int32
	fmt.Fscan(reader, &n, &m, &k)

	arr = make([]int64, n)
	seg = make([]int64, n*4)
	lazy = make([]int64, n*4)

	for i := int32(0); i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	build(0, 0, n-1)
	for i := int32(0); i < m+k; i++ {
		var a, b, c int32
		var d int64
		fmt.Fscan(reader, &a)
		if a == 1 {
			fmt.Fscan(reader, &b, &c, &d)
			b--
			c--
			update(0, 0, n-1, b, c, d)
		} else {
			fmt.Fscan(reader, &b, &c)
			b--
			c--
			fmt.Fprintln(writer, query(0, 0, n-1, b, c))
		}
	}

}