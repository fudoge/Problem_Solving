impl Solution {
    fn check(pref: &Vec<Vec<i32>>, k: usize, threshold: i32) -> bool {
        for i in k..pref.len() {
            for j in k..pref[0].len() {
                let sum = pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k];
                if sum <= threshold {
                    return true
                }
            }
        }

        false
    }
    pub fn max_side_length(mat: Vec<Vec<i32>>, threshold: i32) -> i32 {
        let m = mat.len();
        let n = mat[0].len();

        let mut pref = vec![vec![0;n+1]; m+1];
        for i in 1..=m {
            for j in 1..=n {
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        let mut ans = 0;
        let mut lo = 1usize;
        let mut hi = m.min(n);
        while lo <= hi {
            let mid = (lo + hi) >> 1;
            if Self::check(&pref, mid, threshold) {
                ans = mid as i32;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        ans
    }
}