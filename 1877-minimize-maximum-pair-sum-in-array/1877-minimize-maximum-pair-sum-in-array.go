func minPairSum(nums []int) int {
    n := len(nums)
    sort.Ints(nums)

    ans := 0
    for i := 0; i < n/2; i++ {
        ans = max(ans, nums[i] + nums[n-i-1])
    }

    return ans
}