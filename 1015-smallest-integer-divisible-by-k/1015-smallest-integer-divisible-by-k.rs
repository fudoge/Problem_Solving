impl Solution {
    pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
        if k == 1 {
            return 1;
        }
        if k % 2 == 0 || k % 5 == 0 {
            return -1;
        }
        let mut first_mod_k = vec![0; k as usize];

        let mut num = 1;
        let mut curr = 1;

        while true {
            if first_mod_k[num as usize] != 0 {
                break;
            }
            first_mod_k[num as usize] = curr;
            num = ((num * 10) + 1) % k;
            curr += 1;
        }

        first_mod_k[0]
    }
}