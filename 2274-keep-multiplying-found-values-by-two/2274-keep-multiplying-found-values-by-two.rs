impl Solution {
    pub fn find_final_value(nums: Vec<i32>, original: i32) -> i32 {
        let mut freq = vec![0; 2001];
        let mut ans = original as usize;
        for num in nums {
            freq[num as usize] += 1;
        }

        while freq[ans] > 0 {
            ans *= 2;
        }

        ans as i32
    }
}