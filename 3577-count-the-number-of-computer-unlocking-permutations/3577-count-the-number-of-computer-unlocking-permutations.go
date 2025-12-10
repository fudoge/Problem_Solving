const MOD int = 1_000_000_007
func countPermutations(complexity []int) int {
    n := len(complexity)
    minVal := math.MaxInt
    fact := make([]int, n);
    fact[0] = 1
    for i := 1; i < n; i++ {
        minVal = min(complexity[i], minVal)
        if minVal <= complexity[0] {
            return 0
        }
        fact[i] = fact[i-1] * i % MOD
    }
    return fact[n-1]
}