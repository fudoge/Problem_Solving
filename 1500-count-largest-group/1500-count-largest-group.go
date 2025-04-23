func countLargestGroup(n int) int {
    mp := make(map[int]int)
    for i := 1; i <= n; i++ {
        x := i
        d := 0
        for x > 0 {
            d += x%10
            x /= 10
        }
        mp[d]++
    }  

    maxSize := 0
    ans := 0
    for _, v := range mp {
        if v > maxSize {
            maxSize = v
            ans = 1
        } else if v == maxSize {
            ans++
        }
    }
    return ans
}