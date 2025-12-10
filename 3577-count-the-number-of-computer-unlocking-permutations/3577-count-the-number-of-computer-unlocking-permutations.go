const MOD int = 1_000_000_007
func countPermutations(complexity []int) int {
    n := len(complexity)
    minVal := math.MaxInt
    fact := make([]int, n);
    fact[0] = 1
    for i := 1; i < n; i++ {
        minVal = min(complexity[i], minVal)
        fact[i] = fact[i-1] * i % MOD
    }
    if minVal <= complexity[0] {
        return 0
    }
    return fact[n-1]
}