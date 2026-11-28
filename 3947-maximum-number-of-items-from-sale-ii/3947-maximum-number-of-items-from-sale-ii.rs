impl Solution {
    pub fn maximum_sale_items(items: Vec<Vec<i32>>, budget: i32) -> i32 {
        let mut items = items;
        items.sort_by_key(|i| i[1]);

        let mut mx = 0usize;

        for item in &items {
            mx = mx.max(item[0] as usize);
        }

        let mut freq = vec![0i32; mx + 1];

        for item in &items {
            freq[item[0] as usize] += 1;
        }

        for i in 1..=mx {
            if freq[i] > 0 {
                for j in (i * 2..=mx).step_by(i) {
                    freq[i] += freq[j];
                }
            }
        }

        let mut budget = budget;
        let mut ans = 0i32;

        if items.is_empty() {
            return 0;
        }

        let mn = items[0][1];

        for item in &items {
            let factor = item[0];
            let price = item[1];

            if price - mn > mn {
                break;
            }

            let cnt = freq[factor as usize] - 1;
            let takes = cnt.min(budget / price);

            budget -= takes * price;
            ans += takes * 2;
        }

        ans += budget / mn;
        ans
    }
}