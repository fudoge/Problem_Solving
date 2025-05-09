const MOD int64 = 1_000_000_007

func bpow(base, exp int64) int64 {
    res := int64(1)
    for exp > 0 {
        if exp % 2 == 1 {
            res = (res * base) % MOD
        }
        exp >>= 1
        base = (base * base) % MOD
    }
    return res
}

func countBalancedPermutations(num string) int {
    n := len(num)
    sum := 0
    for _, d := range num {
        sum += int(d-'0')
    }
    if sum % 2 == 1 {
        return 0
    }

    fact, invFact := make([]int64, 81), make([]int64, 81)
    fact[0] = 1
    for i := int64(1); i <= 80; i++ {
        fact[i] = (fact[i-1] * i) % MOD
    }
    invFact[80] = bpow(fact[80], MOD-2)
    for i := int64(79); i >= 0; i-- {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD
    }

    halfSum, halfLen := sum/2, n/2
    dp := make([][]int64, halfSum+1)
    for i := 0; i <= halfSum; i++ {
        dp[i] = make([]int64, halfLen+1)
    }
    dp[0][0] = 1

    freq := make([]int, 10)
    for _, x := range num {
        d := int(x - '0')
        freq[d]++
        for i := halfSum; i >= d; i-- {
            for j := halfLen; j > 0; j-- {
                dp[i][j] = (dp[i][j] + dp[i-d][j-1]) % MOD
            }
        }
    }

    res := (((dp[halfSum][halfLen] * fact[halfLen]) % MOD) * fact[n-halfLen]) % MOD
    for _, d := range freq {
        res = (res * invFact[d]) % MOD
    }

    return int(res)
}