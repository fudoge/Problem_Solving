func maxProfit(prices []int, strategy []int, k int) int64 {
    n := len(prices) 
    k2 := k/2

    pref := make([]int64, n+1)
    for i := 0; i < n; i++ {
        pref[i+1] = pref[i] + (int64(prices[i]) * int64(strategy[i]))
    }

    modify := int64(0)
    for i := k2; i < k; i++ {
        modify += int64(prices[i])
    }
    ans := max(pref[n], modify + pref[n] - pref[k])

    for i := 1; i + k <= n; i++ {
        modify += int64(prices[i+k-1] - prices[i+k2-1])
        ans = max(ans, modify + pref[n] - pref[i+k] + pref[i])
    }

    return ans
}