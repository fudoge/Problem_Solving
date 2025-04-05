func subsetXORSum(nums []int) int {
    ans := 0
    for _, num := range nums {
        ans |= num
    }

    return ans * (1 << (len(nums)-1))
}