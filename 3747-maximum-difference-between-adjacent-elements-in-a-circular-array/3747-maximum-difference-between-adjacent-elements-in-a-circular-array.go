func maxAdjacentDistance(nums []int) int {
    ans := 0
    for i := 0; i < len(nums); i++ {
        diff := nums[i] - nums[(i+1)%len(nums)]
        if diff < 0 {
            diff = -diff
        }
        ans = max(ans, diff)
    }

    return ans
}