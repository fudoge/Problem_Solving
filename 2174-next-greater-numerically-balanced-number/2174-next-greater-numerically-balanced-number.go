func nextBeautifulNumber(n int) int {
	nums := make([]int, 0)
	freq := make([]int, 10)
	generate(0, &nums, freq)
	sort.Ints(nums)

	ub := sort.Search(len(nums), func(i int) bool {
		return nums[i] > n
	})
	return nums[ub]
}

func generate(curr int, nums *[]int, freq []int) {
	if curr > 0 && isBeautiful(freq) {
		*nums = append(*nums, curr)
	}
	if curr > 1224444 {
		return
	}

	for i := 1; i <= 6; i++ {
		if freq[i] < i {
			freq[i]++
			generate(curr*10+i, nums, freq)
			freq[i]--
		}
	}
}

func isBeautiful(freq []int) bool {
	for i := 1; i <= 6; i++ {
		if freq[i] > 0 && freq[i] != i {
			return false
		}
	}
	return true
}
