impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let mut arr = nums.clone();
        let mut n = arr.len();
        if n == 1 {
            return true
        }
        arr.extend_from_slice(&nums);

        let mut last = nums[0];
        let mut streak = 0;

        for i in 1..(2*n) {
            if arr[i] >= last {
                streak += 1;
            } else {
                streak = 0;
            }

            if streak == n-1 {
                return true
            }
            last = arr[i];
        }

        false
    }
}