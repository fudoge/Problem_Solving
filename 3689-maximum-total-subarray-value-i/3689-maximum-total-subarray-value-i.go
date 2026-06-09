func maxTotalValue(nums []int, k int) int64 {
    minVal := math.MaxInt    
    maxVal := math.MinInt

    for _, num := range nums {
        minVal = min(minVal, num)
        maxVal = max(maxVal, num)
    }

    return int64(maxVal - minVal) * int64(k)
}