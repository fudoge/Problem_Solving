func maximumDifference(nums []int) int {
    prefMin := nums[0]

    ans := -1
    for i := 1; i < len(nums); i++ {
        if nums[i] > prefMin {
            ans = max(ans, nums[i] - prefMin)
        } else {
            prefMin = min(prefMin, nums[i])
        }
    }

    return ans
}