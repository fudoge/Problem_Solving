func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
	mat := make([][]int, m)
	for i := 0; i < m; i++ {
		mat[i] = make([]int, n)
	}

	for _, guard := range guards {
		mat[guard[0]][guard[1]] = 2
	}

	for _, wall := range walls {
		mat[wall[0]][wall[1]] = 3
	}

	ans := m*n - len(guards) - len(walls)
	for _, guard := range guards {
		ans -= propagate(guard[0], guard[1], mat)
	}

	return ans
}

func propagate(r, c int, mat [][]int) int {
	res := 0
	dr := 1
	for r+dr < len(mat) {
		if mat[r+dr][c] == 0 {
			mat[r+dr][c] = 1
			res++
		} else if mat[r+dr][c] > 1 {
			break
		}
		dr++
	}
	dr = -1
	for r+dr >= 0 {
		if mat[r+dr][c] == 0 {
			mat[r+dr][c] = 1
			res++
		} else if mat[r+dr][c] > 1 {
			break
		}
		dr--
	}

	dc := 1
	for c+dc < len(mat[0]) {
		if mat[r][c+dc] == 0 {
			mat[r][c+dc] = 1
			res++
		} else if mat[r][c+dc] > 1 {
			break
		}
		dc++
	}
	dc = -1
	for c+dc >= 0 {
		if mat[r][c+dc] == 0 {
			mat[r][c+dc] = 1
			res++
		} else if mat[r][c+dc] > 1 {
			break
		}
		dc--
	}

	return res
}
