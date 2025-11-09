impl Solution {
    pub fn count_operations(num1: i32, num2: i32) -> i32 {
        let mut ans = 0;        
        let mut n1 = num1;
        let mut n2 = num2;


        while n1 > 0 && n2 > 0 {
            if n1 >= n2 {
                n1 -= n2;
            } else {
                n2 -= n1;
            }
            ans += 1;
        }

        ans
    }
}