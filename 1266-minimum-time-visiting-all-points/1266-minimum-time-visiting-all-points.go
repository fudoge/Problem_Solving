func minTimeToVisitAllPoints(points [][]int) int {
    ans := 0
    for i := 0; i < len(points)-1; i++ {
        xDiff := abs(points[i+1][0] - points[i][0])
        yDiff := abs(points[i+1][1] - points[i][1])
        ans += max(xDiff, yDiff)
    }    
    return ans
}

func abs(x int) int {
    if x < 0 {
        x *= -1
    }
    return x
}