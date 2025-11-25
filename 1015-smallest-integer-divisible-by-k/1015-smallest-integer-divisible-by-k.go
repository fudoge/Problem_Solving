func smallestRepunitDivByK(k int) int {
	if k == 1 {
		return 1
	}
	if k%2 == 0 || k%5 == 0 {
		return -1
	}

	num := 1
	curr := 1
	firstModK := make([]int, k)
	for {
		if firstModK[num] != 0 {
			break
		}
		firstModK[num] = curr
		num = ((num * 10) + 1) % k
		curr++
	}

	return firstModK[0]
}
