impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let exp = n.ilog2();

        (1 << (exp + 1)) - 1
    }
}