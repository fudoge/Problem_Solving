const MOD int = 1000000007

func numSub(s string) int {
	n := len(s)
	left := 0
	ans := 0

	for right := 0; right < n; right++ {
		if s[right] == '0' {
			left = right + 1
		} else {
			ans = (ans + (right - left + 1)) % MOD
		}
	}

	return ans
}
