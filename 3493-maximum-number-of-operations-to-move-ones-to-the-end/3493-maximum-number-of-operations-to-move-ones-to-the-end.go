func maxOperations(s string) int {
	ans := 0
	n := len(s)
	init := n - 1
	for init >= 0 && s[init] == '1' {
		init--
	}

	groupSize := 0
	suffixGroups := 0
	for i := init; i >= 0; i-- {
		if s[i] == '1' {
			groupSize++
			ans += suffixGroups + 1
		} else {
			if groupSize > 0 {
				suffixGroups++
				groupSize = 0
			}
		}
	}

	return ans
}
