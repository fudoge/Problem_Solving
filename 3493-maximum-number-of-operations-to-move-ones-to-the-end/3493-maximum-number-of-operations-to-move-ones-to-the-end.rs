impl Solution {
    pub fn max_operations(s: String) -> i32 {
        let n = s.len();
        let mut ans = 0;

        let bs = s.as_bytes();

        let mut init = n as isize - 1;
        while init >= 0 && bs[init as usize] == b'1' {
            init -= 1;
        }

        let mut group_size = 0;
        let mut suffix_groups = 0;
        for i in (0..init + 1).rev() {
            let i = i as usize;
            if bs[i] == b'1' {
                group_size += 1;
                ans += suffix_groups + 1;
            } else {
                if group_size > 0 {
                    suffix_groups += 1;
                    group_size = 0;
                }
            }
        }

        ans
    }
}