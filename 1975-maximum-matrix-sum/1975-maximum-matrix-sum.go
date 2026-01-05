func maxMatrixSum(matrix [][]int) int64 {
    n := len(matrix)
    maximumNeg := math.MaxInt
    ans := int64(0)
    cnt := 0

    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if matrix[i][j] < 0 {
                cnt++
            }
            num := int(math.Abs(float64(matrix[i][j])))
            maximumNeg = min(maximumNeg, num);
            ans += int64(num)
        }
    }

    if cnt % 2 == 1 {
        ans -= 2 * int64(maximumNeg)
    }
    return ans
}