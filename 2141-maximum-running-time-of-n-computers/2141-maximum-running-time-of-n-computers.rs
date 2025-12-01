impl Solution {
    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        let n = n as i64;
        let mut batteries: Vec<i64> = batteries.into_iter().map(|x| x as i64).collect();

        let sum: i64 = batteries.iter().sum();

        let mut lo: i64 = 0;
        let mut hi: i64 = sum / n;
        let mut ans: i64 = 0;

        while lo <= hi {
            let mid = (lo + hi) / 2;

            if Self::check(mid, n, &batteries) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        ans
    }

    fn check(time: i64, n: i64, batteries: &Vec<i64>) -> bool {
        let mut tot: i64 = 0;
        for &b in batteries {
            tot += b.min(time);
        }
        tot >= n * time
    }
}