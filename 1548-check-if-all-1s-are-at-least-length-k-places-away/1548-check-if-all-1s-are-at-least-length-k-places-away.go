func kLengthApart(nums []int, k int) bool {
	last := -k - 1
	for curr := 0; curr < len(nums); curr++ {
		if nums[curr] == 1 {
			if curr-last <= k {
				return false
			}
			last = curr
		}
	}
	return true
}
