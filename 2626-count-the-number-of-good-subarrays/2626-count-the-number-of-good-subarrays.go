func countGood(nums []int, k int) int64 {
	n := len(nums)
	ans := int64(0)    
	freq := make(map[int]int)
	pairs := 0
	left := 0
	for right, num := range nums {
		pairs += freq[num]
		freq[num]++	

		for pairs >= k {
			ans += int64(n-right)
			freq[nums[left]]--
			pairs -= freq[nums[left]];
			left++
		}
	}

	return ans
}