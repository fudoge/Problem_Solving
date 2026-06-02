func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
    n := len(landStartTime)
    m := len(waterStartTime)

    ans := math.MaxInt
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            landFinish := landStartTime[i] + landDuration[i]
            waterFinish := max(landFinish, waterStartTime[j]) + waterDuration[j]
            ans = min(ans, waterFinish)
        }
    }    

    for j := 0; j < m; j++ {
        for i := 0; i < n; i++ {
            waterFinish := waterStartTime[j] + waterDuration[j]
            landFinish := max(waterFinish, landStartTime[i]) + landDuration[i]
            ans = min(ans, landFinish)
        }
    }    

    return ans
}