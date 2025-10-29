func smallestNumber(n int) int {
	return (1 << (int(math.Log2(float64(n))) + 1)) - 1
}
