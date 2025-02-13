package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD int64 = 1000000007

var (
	arr []int32
	seg []int32
)

func build(index, l, r int32) {
	if l == r {
		seg[index] = arr[l]
		return
	}

	mid := (l + r) / 2
	build(index*2, l, mid)
	build(index*2+1, mid+1, r)
	seg[index] = int32((int64(seg[index*2]) * int64(seg[index*2+1])) % MOD)
}

func update(index, target, newVal, l, r int32) {
	if l == r {
		arr[l] = newVal
		seg[index] = newVal
		return
	}

	mid := (l + r) / 2
	if target <= mid {
		update(index*2, target, newVal, l, mid)
	} else {
		update(index*2+1, target, newVal, mid+1, r)
	}
	seg[index] = int32((int64(seg[index*2]) * int64(seg[index*2+1])) % MOD)
}

func query(index, ql, qr, l, r int32) int32 {
	if qr < l || r < ql {
		return 1
	}
	if ql <= l && r <= qr {
		return int32(seg[index])
	}

	mid := (l + r) / 2
	return int32((int64(query(index*2, ql, qr, l, mid)) * int64(query(index*2+1, ql, qr, mid+1, r)) % MOD))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, k int32
	fmt.Fscan(reader, &n, &m, &k)

	arr = make([]int32, n+1)
	seg = make([]int32, 4*(n+1))

	for i := int32(1); i <= n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	build(1, 1, n)

	for i := int32(0); i < m+k; i++ {
		var a, b, c int32
		fmt.Fscan(reader, &a, &b, &c)

		if a == 1 {
			update(1, b, c, 1, n)
		} else {
			fmt.Fprintln(writer, query(1, b, c, 1, n))
		}
	}
}
