func minimumOperations(nums []int) int {
	freq := make(map[int]int)
	dup := 0

	for _, num := range nums {
		freq[num]++
	}

	for _, v := range freq {
		if v > 1 {
			dup++
		}
	}

    if dup == 0 {
        return 0
    }

	for i := 0; i < len(nums); i += 3 {
		freq[nums[i]]--
		if freq[nums[i]] == 1 {
			dup--
		}
		if i+1 >= len(nums) {
			continue
		}
		freq[nums[i+1]]--
		if freq[nums[i+1]] == 1 {
			dup--
		}
		if i+2 >= len(nums) {
			continue
		}
		freq[nums[i+2]]--
		if freq[nums[i+2]] == 1 {
			dup--
		}

		if dup == 0 {
			return i/3 + 1
		}
	}

	return len(nums)/3 + 1
}
