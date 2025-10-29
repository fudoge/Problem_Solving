func smallestNumber(n int) int {
	exp := int(math.Log2(float64(n)))

	return (1 << (exp + 1)) - 1
}
