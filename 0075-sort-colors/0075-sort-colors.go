func sortColors(nums []int)  {
    l := 0
    r := len(nums) -1
    m := 0

    for m <= r {
        if nums[m] == 0 {
            nums[l], nums[m] = nums[m], nums[l]
            l++
            m++
        }  else if nums[m] == 1 {
            m++
        } else {
            nums[r], nums[m] = nums[m], nums[r]
            r--
        }
    } 
}