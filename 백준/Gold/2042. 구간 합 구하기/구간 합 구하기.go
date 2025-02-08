package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	n, m, k int32
	arr     []int64
	seg     []int64
)

func build(index, l, r int32) {
	if l == r {
		seg[index] = arr[l]
		return
	}

	mid := (l + r) / 2
	build(index*2, l, mid)
	build(index*2+1, mid+1, r)

	seg[index] = seg[index*2] + seg[index*2+1]
}

func update(index, target int32, newVal int64, l, r int32) {
	if l == r {
		arr[target] = newVal
		seg[index] = newVal
		return
	}

	mid := (l + r) / 2
	if target <= mid {
		update(index*2, target, newVal, l, mid)
	} else {
		update(index*2+1, target, newVal, mid+1, r)
	}
	seg[index] = seg[index*2] + seg[index*2+1]
}

func subarrSum(index, ql, qr, l, r int32) int64 {
	if qr < l || ql > r {
		return 0
	}

	if ql <= l && r <= qr {
		return seg[index]
	}

	mid := (l + r) / 2
	lRes := subarrSum(index*2, ql, qr, l, mid)
	rRes := subarrSum(index*2+1, ql, qr, mid+1, r)

	return lRes + rRes
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n, &m, &k)
	arr = make([]int64, n+1)
	seg = make([]int64, 4*(n+1))

	for i := int32(1); i <= n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	build(1, 1, n)

	for i := int32(0); i < m+k; i++ {
		var a, b int32
		var c int64
		fmt.Fscan(reader, &a, &b, &c)

		if a == 1 {
			update(1, b, c, 1, n)
		} else {
			res := subarrSum(1, b, int32(c), 1, n)
			fmt.Fprintln(writer, res)
		}
	}

}