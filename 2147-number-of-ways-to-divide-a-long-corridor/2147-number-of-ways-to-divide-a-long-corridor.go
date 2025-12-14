const MOD int = 1_000_000_007
func numberOfWays(corridor string) int {
    n := len(corridor)
    ans := 1

    streak := 0
    cnt := 0
    for i := 0; i < n; i++ {
        if corridor[i] == 'S' {
            streak++
            cnt++
            if streak >= 2 {
                j := i+1
                for j < n && corridor[j] == 'P' {
                    j++
                }
                if j < n {
                    ans = (ans * (j-i)) % MOD
                }
                streak = 0
                j = i
            }
        }
    }

    if cnt%2 == 1 || cnt == 0 {
        return 0
    }

    return ans
}