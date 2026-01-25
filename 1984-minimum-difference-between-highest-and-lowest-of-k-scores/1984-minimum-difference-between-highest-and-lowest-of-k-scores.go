func minimumDifference(nums []int, k int) int {
    n := len(nums)
    sort.Ints(nums) 
    ans := math.MaxInt
    for i := 0; i <= n-k; i++ {
        ans = min(ans, nums[i+k-1] - nums[i])
    }
    return ans
}