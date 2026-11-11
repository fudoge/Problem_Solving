impl Solution {
    pub fn minimum_cost(cost1: i32, cost2: i32, cost_both: i32, need1: i32, need2: i32) -> i64 {
        let mut ans: i64 = 0;
        let mut need1 = need1;
        let mut need2 = need2;
        if (cost_both < cost1 + cost2) {
            let le = need1.min(need2);
            ans += le as i64 * cost_both as i64;
            need1 -= le;
            need2 -= le;
        }

        if (need1 > 0) {
            let cost = cost1.min(cost_both);
            ans += need1 as i64 * cost as i64;
            need1 = 0;
        }

        if (need2 > 0) {
            let cost = cost2.min(cost_both);
            ans += need2 as i64 * cost as i64;
            need2 = 0;
        }

        ans
    }
}