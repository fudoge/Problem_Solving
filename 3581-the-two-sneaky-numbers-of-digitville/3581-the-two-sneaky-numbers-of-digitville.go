func getSneakyNumbers(nums []int) []int {
	ans := make([]int, 0, 2)
	freq := make([]int, len(nums)-2)
	for _, num := range nums {
		if freq[num] == 1 {
			ans = append(ans, num)
		}
		freq[num]++
	}
	return ans
}
