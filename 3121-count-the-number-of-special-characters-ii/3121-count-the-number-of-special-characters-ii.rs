impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut lower_last: [i32; 26] = [i32::MAX; 26];
        let mut upper_first: [i32; 26] = [i32::MIN; 26];

        for (i, ch) in word.char_indices() {
            if ch >= 'a' && ch <= 'z' {
                let ord = ch as usize - 'a' as usize;
                lower_last[ord] = i as i32;
            } else {
                let ord = ch as usize - 'A' as usize;
                if upper_first[ord] == i32::MIN {
                    upper_first[ord] = i as i32;
                }
            }
        }

        let mut ans = 0;
        for i in 0..26 {
            if lower_last[i] < upper_first[i] {
                ans += 1;
            }
        }

        ans
    }
}