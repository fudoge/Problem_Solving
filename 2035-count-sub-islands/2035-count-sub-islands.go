var m, n int

func dfs(r, c int, grid1, grid2 [][]int) bool {
	if r < 0 || r >= m || c < 0 || c >= n || grid2[r][c] == 0 {
		return true
	}
	flag := grid1[r][c] == 1
	grid2[r][c] = 0
	flag = dfs(r-1, c, grid1, grid2) && flag
	flag = dfs(r+1, c, grid1, grid2) && flag
	flag = dfs(r, c-1, grid1, grid2) && flag
	flag = dfs(r, c+1, grid1, grid2) && flag

	return flag
}

func countSubIslands(grid1, grid2 [][]int) int {
	m = len(grid1)
	n = len(grid1[0])
	ans := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid1[i][j] == 1 && grid2[i][j] == 1 {
				if dfs(i, j, grid1, grid2) {
					ans++
				}
			}
		}
	}
	return ans
}