func largestAltitude(gain []int) int {
    ans := 0
    curr := 0
    for _, v := range gain {
        curr += v
        ans = max(ans, curr)
    }    
    return ans
}