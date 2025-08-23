package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer

const MOD int = 1000000007

var fact []int
var invfact []int

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fact = make([]int, 2001)
	fact[0] = 1
	for i := 1; i < 2001; i++ {
		fact[i] = (fact[i-1] * i) % MOD
	}
	invfact = make([]int, 2001)
	invfact[2000] = bpow(fact[2000], MOD-2)
	for i := 1999; i >= 0; i-- {
		invfact[i] = (invfact[i+1] * (i + 1)) % MOD
	}

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			var temp int
			fmt.Fscanf(reader, "%d", &temp)
		}
	}

	ans1 := nCr(2*n, n)
	ans2 := (n * n) % MOD

	fmt.Fprintf(writer, "%d %d\n", ans1, ans2)
}

func bpow(base, exp int) int {
	res := 1
	base %= MOD
	for exp > 0 {
		if exp&1 == 1 {
			res = (res * base) % MOD
		}
		base = (base * base) % MOD
		exp >>= 1
	}

	return res
}

func nCr(n, r int) int {
	if r < 0 || r > n {
		return 0
	}
	numerator := fact[n]
	denominator := (invfact[r] * invfact[n-r]) % MOD
	return (numerator * denominator) % MOD
}
