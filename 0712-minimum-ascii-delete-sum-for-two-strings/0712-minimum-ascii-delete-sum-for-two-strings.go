func minimumDeleteSum(s1 string, s2 string) int {
    n := len(s1) 
    m := len(s2) 

    dp := make([][]int, n+1)
    for i := 0; i <= n; i++ {
        dp[i] = make([]int, m+1)
    }

    for i := 1; i <= n; i++ {
        for j := 1; j <= m; j++ {
            if s1[i-1] == s2[j-1] {
                dp[i][j] = dp[i-1][j-1] + int(s1[i-1])
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            }
        }
    }

    ans := 0
    for _, ch := range s1 { ans += int(ch) }
    for _, ch := range s2 { ans += int(ch) }
    return ans - 2 * dp[n][m]
}