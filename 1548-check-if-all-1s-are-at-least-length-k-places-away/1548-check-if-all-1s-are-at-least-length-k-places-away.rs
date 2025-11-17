impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let mut last = -k as isize - 1;
        for curr in 0..nums.len() {
            if nums[curr] == 1 {
                if curr - last as usize <= k as usize {
                    return false;
                }
                last = curr as isize;
            }
        }

        true
    }
}