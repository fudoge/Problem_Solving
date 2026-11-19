impl Solution {
    pub fn minimize_sum(nums: Vec<i32>) -> i32 {
        let (mut h1, mut h2, mut h3, mut l1, mut l2, mut l3) = (i32::MIN, i32::MIN, i32::MIN, i32::MAX, i32::MAX, i32::MAX);

        for num in &nums {
            if *num > h1 {
                h3 = h2;
                h2 = h1;
                h1 = *num
            } else if *num > h2 {
                h3 = h2;
                h2 = *num;
            } else if *num > h3 {
                h3 = *num;
            }

            if *num < l1 {
                l3 = l2;
                l2 = l1;
                l1 = *num;
            } else if *num < l2 {
                l3 = l2;
                l2 = *num;
            } else if *num < l3 {
                l3 = *num;
            }
        }

        let cand1 = h1 - l3;
        let cand2 = h2 - l2;
        let cand3 = h3 - l1;

        cand1.min(cand2).min(cand3)
    }
}