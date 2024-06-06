func numIslands(grid [][]byte) int {
	n := len(grid)
	m := len(grid[0])
	ans := 0
	di := []int{1, -1, 0, 0}
	dj := []int{0, 0, 1, -1}

	visited := make([][]bool, n)
	for i := range visited {
		visited[i] = make([]bool, m)
	}

	q := make([][2]int, 0)

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == '1' && !visited[i][j] {
				ans++
				q = append(q, [2]int{i, j})
				visited[i][j] = true

				for len(q) > 0 {
					curr := q[0]
					q = q[1:]

					for k := 0; k < 4; k++ {
						ni := curr[0] + di[k]
						nj := curr[1] + dj[k]

						if ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && !visited[ni][nj] {
							q = append(q, [2]int{ni, nj})
							visited[ni][nj] = true
						}
					}
				}
			}
		}
	}

	return ans
}