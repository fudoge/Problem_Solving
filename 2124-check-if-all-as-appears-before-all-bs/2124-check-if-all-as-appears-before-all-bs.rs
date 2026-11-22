impl Solution {
    pub fn check_string(s: String) -> bool {
        let mut bc = 0; 
        for ch in s.chars() {
            if ch == 'b' {
                bc += 1;
            } else if bc > 0 {
                return false
            }
        }

        true
    }
}