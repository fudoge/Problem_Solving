use std::cmp;
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut ans = i32::MAX;
        let n = nums.len();

        for i in 0..n {
            if nums[i] == 1 {
                let cnt1 = nums.iter().filter(|&n| *n == 1).count();
                return (n - cnt1) as i32;
            }
            let mut g = nums[i];
            for j in i + 1..n {
                g = Self::gcd(g, nums[j]);
                if g == 1 {
                    ans = cmp::min(ans, (j - i + n - 1) as i32);
                    break;
                }
            }
        }

        ans = if ans == i32::MAX { -1 } else { ans };
        ans
    }

    pub fn gcd(a: i32, b: i32) -> i32 {
        let res = if b == 0 { a } else { Self::gcd(b, a % b) };
        res
    }
}