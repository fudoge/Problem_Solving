impl Solution {
    pub fn number_of_ways(corridor: String) -> i32 {
        let MOD :i64 = 1_000_000_007;
        let bs = corridor.as_bytes();
        let n = corridor.len();
        let mut ans = 1i64;

        let mut streak = 0;
        let mut cnt = 0;
        for i in 0..n {
            if bs[i] == b'S' {
                streak += 1;
                cnt += 1;
                if streak >= 2 {
                    let mut j = i+1;
                    while j < n && bs[j] == b'P' {
                        j += 1;
                    }
                    if j < n {
                        ans = (ans * (j - i) as i64) % MOD;
                    }
                    streak = 0;
                }
            }
        } 

        if cnt % 2 == 1 || cnt == 0 {
            return 0
        }

        ans as i32
    }
}