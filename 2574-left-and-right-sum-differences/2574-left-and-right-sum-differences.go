func leftRightDifference(nums []int) []int {
    n := len(nums)
    ls := make([]int, n)
    rs := make([]int, n)
    ans := make([]int, n)    

    for i := 1; i < n; i++ {
        ls[i] = nums[i-1] + ls[i-1]    
    }
    for i := n-2; i >= 0; i-- {
        rs[i] = nums[i+1] + rs[i+1]    
    }

    for i := 0; i < n; i++ {
        ans[i] = ls[i] - rs[i]
        if ans[i] < 0 {
            ans[i] *= -1 
        }
    }

    return ans
}