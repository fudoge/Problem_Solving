impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut ans = 0; 
        for num in nums {
            let n = num as i64;
            let root = (n as f64).sqrt() as i64;

            let mut cnt = 0;
            let mut sum = n+1;

            for i in 2..=root {
                if n%i == 0 {
                    if i*i == n {
                        cnt += 1;
                        sum += i;
                    } else {
                        cnt += 2;
                        sum += i + n/i;
                    }
                }
                if cnt > 2 {
                    break;
                }
            }
            if cnt == 2 {
                ans += sum;
            }
        }

        ans as i32
    }
}