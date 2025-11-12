func minOperations(nums []int) int {
	ans := math.MaxInt
	n := len(nums)

	for i := 0; i < n; i++ {
		if nums[i] == 1 {
			cnt1 := 0
			for j := 0; j < n; j++ {
				if nums[j] == 1 {
					cnt1++
				}
			}
			return n - cnt1
		}

		g := nums[i]
		for j := i + 1; j < n; j++ {
			g = gcd(g, nums[j])
			if g == 1 {
				ans = min(ans, j-i+n-1)
				break
			}
		}
	}

	if ans == math.MaxInt {
		return -1
	}

	return ans

}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}

	return gcd(b, a%b)
}
