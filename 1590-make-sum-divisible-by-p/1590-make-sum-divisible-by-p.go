func minSubarray(nums []int, p int) int {
	n := len(nums)

	sum := 0
	for _, num := range nums {
		sum += num
	}
	target := sum % p
	if target == 0 {
		return 0
	}

	ans := n
	pref := 0
	mp := make(map[int]int)
	mp[0] = -1
	for i, num := range nums {
		pref = (pref + num) % p
		need := (pref - target + p) % p
		if _, ok := mp[need]; ok {
			ans = min(ans, i-mp[need])
		}

		mp[pref] = i
	}

	if ans == n {
		return -1
	}
	return ans
}
