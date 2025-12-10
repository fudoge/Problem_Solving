impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let MOD: i64 = 1_000_000_007;
        let n = complexity.len();
        let mut fact = vec![0i64; n];
        fact[0] = 1;

        let mut min_val = i32::MAX;
        for i in 1..n {
            min_val = min_val.min(complexity[i]);
            if min_val <= complexity[0] {
                return 0
            }
            fact[i] = fact[i-1] * (i as i64) % MOD;
        }

        fact[n-1] as i32
    }
}