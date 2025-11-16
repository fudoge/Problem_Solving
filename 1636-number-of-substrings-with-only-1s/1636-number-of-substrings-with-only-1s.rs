impl Solution {
    pub fn num_sub(s: String) -> i32 {
        let bs = s.as_bytes();
        let MOD = 1e9 as i64 + 7;
        let n = s.len();
        let mut left = 0 as usize;
        let mut ans = 0 as i64;

        for right in 0..n {
            if bs[right] == b'0' {
                left = right + 1;
            } else {
                ans = (ans + (right - left + 1) as i64) % MOD;
            }
        }

        ans as i32
    }
}