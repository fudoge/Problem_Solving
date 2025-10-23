func hasSameDigits(s string) bool {
	last := make([]int, 0, 100)
	for i := 0; i < len(s)-1; i++ {
		last = append(last, (int(s[i]-'0')+int(s[i+1]-'0'))%10)
	}

	for len(last) > 2 {
		curr := make([]int, 0, 100)
		for i := 0; i < len(last)-1; i++ {
			curr = append(curr, (last[i]+last[i+1])%10)
		}
		last = curr
	}

	return last[0] == last[1]
}
