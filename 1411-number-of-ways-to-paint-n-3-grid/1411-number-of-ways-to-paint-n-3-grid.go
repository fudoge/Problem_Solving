func numOfWays(n int) int {
    MOD := 1000000007
    A := 6
    B := 6

    for i := 2; i <= n; i++ {
        newA := ((A * 3) % MOD + (B * 2) % MOD) % MOD
        newB := ((A * 2) % MOD + (B * 2) % MOD) % MOD
        A = newA
        B = newB
    } 

    return (A + B) % MOD
}