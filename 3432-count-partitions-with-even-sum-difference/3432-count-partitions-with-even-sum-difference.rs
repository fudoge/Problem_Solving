impl Solution {
    pub fn count_partitions(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut l: i32 = 0;
        let mut r: i32 = nums.iter().sum();
        let mut ans = 0;
        for i in 0..n - 1 {
            l += nums[i];
            r -= nums[i];
            if (l - r).abs() % 2 == 0 {
                ans += 1;
            }
        }

        ans
    }
}