func minOperations(nums []int) int {
	stack := make([]int, 0, len(nums)/2)
	ans := 0

	for _, num := range nums {
		for len(stack) > 0 && stack[len(stack)-1] > num {
			stack = stack[0 : len(stack)-1]
		}

		if num == 0 {
			continue
		}

		if len(stack) == 0 || stack[len(stack)-1] < num {
			ans++
			stack = append(stack, num)
		}
	}

	return ans

}
