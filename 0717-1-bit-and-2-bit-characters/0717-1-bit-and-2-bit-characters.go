func isOneBitCharacter(bits []int) bool {
	n := len(bits)
	for i := 0; i < n; i++ {
		flag := false
		if bits[i] == 1 {
			i++
			flag = true
		}
		if i == n-1 && flag {
			return false
		}
	}

	return true
}
