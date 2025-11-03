impl Solution {
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
        let n = colors.len();
        let s: Vec<char> = colors.chars().collect();
        let mut ans = 0;
        let mut i: usize = 0;

        while i < n {
            let mut j = i + 1;
            let mut sum = needed_time[i];
            let mut maximum = needed_time[i];

            while j < n && s[i] == s[j] {
                sum += needed_time[j];
                maximum = std::cmp::max(maximum, needed_time[j]);
                j += 1;
            }

            ans += (sum - maximum);
            i = j;
        }

        ans
    }
}