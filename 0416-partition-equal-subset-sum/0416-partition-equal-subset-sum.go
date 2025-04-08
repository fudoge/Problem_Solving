func canPartition(nums []int) bool {
    sum := 0
    for _, num := range nums {
        sum += num
    }

    if sum %2 ==1 {
        return false
    }
    target := sum>>1

    dp := make([]bool, target+1)
    dp[0] = true

    for _, num := range nums{
        for j := target; j >= num; j-- {
            dp[j] = dp[j] || dp[j-num]
        }
    }

    return dp[target]
}