func maximumTripletValue(nums []int) int64 {
    n := len(nums)    

    leftMaxima := make([]int, n)
    rightMaxima := make([]int, n)

    leftMaxima[0] = -1
    for i:= 1; i < n; i++ {
        leftMaxima[i] = max(leftMaxima[i-1], nums[i-1])
    } 

    rightMaxima[n-1] = -1
    for i:=n-2; i >= 0; i-- {
        rightMaxima[i] = max(rightMaxima[i+1], nums[i+1])
    }

    ans := int64(0)
    for i:= 1; i < n-1; i++ {
        val := int64(leftMaxima[i] - nums[i]) * int64(rightMaxima[i])
        if val > ans {
            ans = val
        }
    }
    return ans
}