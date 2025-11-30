use std::collections::HashMap;
impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let p = p as i64;
        let n = nums.len();

        let sum: i64 = nums.iter().map(|&x| x as i64).sum();
        let target = sum % p;
        if target == 0 {
            return 0;
        }

        let mut map: HashMap<i64, i32> = HashMap::new();
        map.insert(0, -1);

        let mut pref: i64 = 0;
        let mut ans = n as i32;

        for (i, &v) in nums.iter().enumerate() {
            pref = (pref + v as i64) % p;
            let need = (pref - target + p) % p;
            if let Some(&idx) = map.get(&need) {
                ans = ans.min(i as i32 - idx);
            }

            map.insert(pref, i as i32);
        }

        if ans == n as i32 {
            -1
        } else {
            ans
        }
    }
}