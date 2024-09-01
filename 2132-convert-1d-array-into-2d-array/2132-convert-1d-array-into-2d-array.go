func construct2DArray(original []int, m int, n int) [][]int {
    if len(original) != m*n {
        return nil
    }

    ans := make([][]int, m)
    for i := 0; i < m; i++ {
        ans[i] = make([]int, n)
        for j := 0; j < n; j++ {
            ans[i][j] = original[i*n+j]
        }
    }

    return ans
}