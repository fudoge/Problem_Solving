func numberOfArrays(differences []int, lower int, upper int) int {
	x := int64(0)
	maxX := int64(0)
	minX := int64(0)

	for _, difference := range differences {
		x += int64(difference)
		maxX = max(maxX, x)
		minX = min(minX, x)
	}

	start := int64(lower) - minX
	end := int64(upper) - maxX

	if start > end {
		return 0
	}
	return int(end - start + 1)
}
