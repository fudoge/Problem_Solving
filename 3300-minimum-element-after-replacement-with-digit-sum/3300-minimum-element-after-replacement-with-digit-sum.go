func minElement(nums []int) int {
    ans := math.MaxInt
    for _, num := range nums {
        curr := 0;
        for num > 0 {
            curr += num % 10
            num /= 10
        }
        ans = min(ans, curr)
    }     
    return ans
}