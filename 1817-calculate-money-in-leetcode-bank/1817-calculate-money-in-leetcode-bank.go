func totalMoney(n int) int {
	ans := 0
	cycle := 0
	day := 0
	for i := 0; i < n; i++ {
		ans += cycle + (day + 1)
		day++
		if day == 7 {
			day = 0
			cycle++
		}
	}
	return ans
}
