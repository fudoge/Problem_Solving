func maximumHappinessSum(happiness []int, k int) int64 {
    sort.Slice(happiness, func(i, j int) bool {
        return happiness[i] > happiness[j]
    })
    ans := int64(0)
    for i := 0; i < k; i++ {
        ans += max(0, int64(happiness[i] - i))
    }
    return ans
}