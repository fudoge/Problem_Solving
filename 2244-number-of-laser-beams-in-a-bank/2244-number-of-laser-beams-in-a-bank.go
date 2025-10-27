func numberOfBeams(bank []string) int {
	n := len(bank)
	m := len(bank[0])
	prev := 0
	ans := 0
	for i := 0; i < n; i++ {
		curr := 0
		for j := 0; j < m; j++ {
			if bank[i][j] == '1' {
				curr++
			}
		}
		if curr > 0 {
			ans += prev * curr
			prev = curr
		}
	}

	return ans
}
