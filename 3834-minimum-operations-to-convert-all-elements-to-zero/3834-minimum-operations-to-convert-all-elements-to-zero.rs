impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut stack = vec![0; 0];
        let mut ans = 0;

        for &num in &nums {
            while stack.len() > 0 && stack[stack.len() - 1] > num {
                stack.pop();
            }

            if num == 0 {
                continue;
            }

            if stack.is_empty() || stack[stack.len() - 1] < num {
                ans += 1;
                stack.push(num);
            }
        }

        ans
    }
}