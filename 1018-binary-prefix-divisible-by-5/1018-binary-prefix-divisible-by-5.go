func prefixesDivBy5(nums []int) []bool {
	n := len(nums)
	ans := make([]bool, 0, n)
	sum := 0

	for _, num := range nums {
		sum += num
		sum %= 5
		if sum == 0 {
			ans = append(ans, true)
		} else {
			ans = append(ans, false)
		}
		sum <<= 1
	}

	return ans
}
