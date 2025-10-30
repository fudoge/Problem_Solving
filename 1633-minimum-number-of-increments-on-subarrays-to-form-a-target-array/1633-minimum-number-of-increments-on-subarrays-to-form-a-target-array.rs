impl Solution {
    pub fn min_number_operations(target: Vec<i32>) -> i32 {
        let mut ans = target[0];
        for i in 1..target.len() {
            let diff = target[i] - target[i - 1];
            if diff > 0 {
                ans += diff;
            }
        }
        ans
    }
}