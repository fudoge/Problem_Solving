impl Solution {
    pub fn min_element(nums: Vec<i32>) -> i32 {
        let mut ans = i32::MAX;
        for num in nums {
            let mut num = num;
            let mut curr = 0;
            while num > 0 {
                curr += num % 10;
                num /= 10;
            }
            ans = ans.min(curr);
        } 
        ans
    }
}