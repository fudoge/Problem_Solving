
const MOD int64 = int64(1e9) + 7

func bpow(base, exp int64) int64 {
	res := int64(1)
	for exp > 0 {
		if exp%2 == 1 {
			res = (res * base) % MOD
			exp--
		}
		base = (base * base) % MOD
		exp >>= 1
	}
	return res
}
func countGoodNumbers(n int64) int {
	return int((bpow(4, n/2) * bpow(5, n/2+n%2)) % MOD)
}
