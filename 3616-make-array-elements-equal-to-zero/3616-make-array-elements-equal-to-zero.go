func countValidSelections(nums []int) int {
	n := len(nums)
	pref := make([]int, n)
	pref[0] = nums[0]
	for i := 1; i < n; i++ {
		pref[i] = pref[i-1] + nums[i]
	}
	ans := 0
	for curr := 0; curr < n; curr++ {
		if nums[curr] == 0 {
			ans += solve(curr, pref)
		}
	}
	return ans
}

func solve(curr int, pref []int) int {
	l := pref[curr]
	r := pref[len(pref)-1] - pref[curr]
	diff := l - r
	res := 0
	if diff == 0 || diff == 1 {
		res++
	}
	if diff == 0 || diff == -1 {
		res++
	}
	return res
}
