func rangeAddQueries(n int, queries [][]int) [][]int {
	diff := newMatrix(n + 1)

	for _, q := range queries {
		r1, c1, r2, c2 := q[0], q[1], q[2], q[3]
		diff[r1][c1]++
		diff[r1][c2+1]--
		diff[r2+1][c1]--
		diff[r2+1][c2+1]++
	}

	for i := 0; i < n; i++ {
		for j := 1; j < n; j++ {
			diff[i][j] += diff[i][j-1]
		}
	}

	for i := 1; i < n; i++ {
		for j := 0; j < n; j++ {
			diff[i][j] += diff[i-1][j]
		}
	}

	ans := newMatrix(n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			ans[i][j] = diff[i][j]
		}
	}

	return ans
}

func newMatrix(size int) [][]int {
	res := make([][]int, size)
	for i := 0; i < size; i++ {
		res[i] = make([]int, size)
	}

	return res
}
