impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        (1 << (n.ilog2() + 1)) - 1
    }
}