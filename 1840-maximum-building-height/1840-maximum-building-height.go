const MAXN int = 1_000_000_000

func maxBuilding(n int, restrictions [][]int) int {
    restrictions = append(restrictions, []int{1, 0})
    restrictions = append(restrictions, []int{n, n-1})
    slices.SortFunc(restrictions, func(i, j []int) int {
        return cmp.Compare(i[0], j[0])
    })
    m := len(restrictions)

	// left -> right
	for i := 1; i < m; i++ {
		dist := restrictions[i][0] - restrictions[i-1][0]
		restrictions[i][1] = min(
			restrictions[i][1],
			restrictions[i-1][1]+dist,
		)
	}

	// right -> left
	for i := m - 2; i >= 0; i-- {
		dist := restrictions[i+1][0] - restrictions[i][0]
		restrictions[i][1] = min(
			restrictions[i][1],
			restrictions[i+1][1]+dist,
		)
	}

	ans := 0
	for i := 0; i < m-1; i++ {
		lID, lH := restrictions[i][0], restrictions[i][1]
		rID, rH := restrictions[i+1][0], restrictions[i+1][1]

		dist := rID - lID

		peak := (lH + rH + dist) / 2
		ans = max(ans, peak)
	}

    return ans
}