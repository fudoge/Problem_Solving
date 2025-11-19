func findFinalValue(nums []int, original int) int {
	freq := make([]int, 2001)
	for _, num := range nums {
		freq[num]++
	}
	for freq[original] > 0 {
		original *= 2
	}

	return original
}
