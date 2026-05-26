impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut lower: [i32; 26] = [0; 26];
        let mut upper: [i32; 26] = [0; 26];

        for ch in word.chars() {
            if ch >= 'a' && ch <= 'z' {
                let char_diff = (ch as u32 - 'a' as u32) as usize;
                lower[char_diff] += 1;
            } else {
                let char_diff = (ch as u32 - 'A' as u32) as usize;
                upper[char_diff] += 1;
            }
        }

        let mut ans = 0;
        for i in 0..26 {
            if lower[i] > 0 && upper[i] > 0 {
                ans += 1;
            }
        }

        ans
    }
}