impl Solution {
    pub fn count_valid_selections(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut pref = vec![0; n];
        pref[0] = nums[0];
        for i in 1..n {
            pref[i] = pref[i - 1] + nums[i];
        }

        let mut ans = 0;
        for curr in 0..n {
            if nums[curr] == 0 {
                ans += Self::solve(curr, &pref);
            }
        }

        ans
    }
    pub fn solve(curr: usize, pref: &Vec<i32>) -> i32 {
        let mut res = 0;
        let l = pref[curr];
        let r = pref[pref.len() - 1] - l;
        let diff = r - l;
        if diff == 0 || diff == 1 {
            res += 1
        }
        if diff == 0 || diff == -1 {
            res += 1
        }

        res
    }
}