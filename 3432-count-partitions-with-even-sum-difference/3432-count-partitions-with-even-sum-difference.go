func countPartitions(nums []int) int {
	n := len(nums)
	l, r := 0, 0
	for _, num := range nums {
		r += num
	}
	ans := 0
	for i := 0; i < n-1; i++ {
		l += nums[i]
		r -= nums[i]
		if (l-r)%2 == 0 {
			ans++
		}
	}

	return ans
}
