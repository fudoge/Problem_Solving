func countSubarrays(nums []int) int {
    ans := 0
    for i := 1; i < len(nums)-1; i++{ 
        if 2*(nums[i-1] + nums[i+1]) == nums[i] {
            ans++
        }
    }
    return ans
}