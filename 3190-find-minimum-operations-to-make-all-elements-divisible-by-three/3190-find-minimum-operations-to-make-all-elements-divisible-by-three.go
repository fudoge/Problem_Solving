func minimumOperations(nums []int) int {
	ans := 0
	for _, n := range nums {
		if n%3 != 0 {
			ans++
		}
	}

	return ans
}
