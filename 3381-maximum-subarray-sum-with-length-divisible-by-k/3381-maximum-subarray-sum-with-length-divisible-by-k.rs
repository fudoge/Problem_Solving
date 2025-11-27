impl Solution {
    pub fn max_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        let k = k as usize;
        let mut ans = i64::MIN;
        let mut minPref = vec![i64::MAX; k];
        let mut pref = 0_i64;

        for i in 0..nums.len() {
            pref += nums[i] as i64;
            let r = (i + 1) % k;

            if (i + 1) % k == 0 {
                ans = ans.max(pref);
            }
            if minPref[r] != i64::MAX {
                ans = ans.max(pref - minPref[r]);
            }
            minPref[r] = minPref[r].min(pref);
        }

        ans
    }
}