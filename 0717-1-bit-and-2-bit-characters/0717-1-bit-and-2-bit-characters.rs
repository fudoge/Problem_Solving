impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let mut i = 0 as usize;
        let n = bits.len();
        while i < n {
            let mut flag = false;
            if bits[i] == 1 {
                i += 1;
                flag = true;
            }
            if i == n-1 && flag {
                return false
            }
            i += 1;
        }
        
        true
    }
}