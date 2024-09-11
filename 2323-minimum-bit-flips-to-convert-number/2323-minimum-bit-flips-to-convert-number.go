func minBitFlips(start int, goal int) int {
    x := start ^ goal
    ans := 0

    for x > 0 {
        ans += x % 2
        x /= 2
    }

    return ans
}