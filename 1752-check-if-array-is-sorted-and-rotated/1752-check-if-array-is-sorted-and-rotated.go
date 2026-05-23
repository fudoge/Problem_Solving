func check(nums []int) bool {
    n := len(nums)
    nums = append(nums, nums...)    
    if n == 1 {
        return true
    }

    last := nums[0]
    streak := 0

    for i := 1; i < 2*n; i++ {
        if nums[i] >= last {
            streak++ 
        } else {
            streak = 0
        }

        if streak == n - 1 {
            return true
        }
        last = nums[i]
    }

    return false
}