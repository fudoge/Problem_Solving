impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut freq = vec![0; nums.len() - 2];

        for num in nums {
            if freq[num as usize] == 1 {
                ans.push(num);
            }
            freq[num as usize] += 1;
        }

        ans
    }
}