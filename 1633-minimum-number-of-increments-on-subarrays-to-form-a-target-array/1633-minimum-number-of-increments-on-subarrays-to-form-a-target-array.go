func minNumberOperations(target []int) int {
	ans := target[0]
	for i := 1; i < len(target); i++ {
		diff := target[i] - target[i-1]
		if diff > 0 {
			ans += diff
		}
	}
	return ans
}
