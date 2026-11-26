impl Solution {
    pub fn can_alice_win(n: i32) -> bool {
        let mut n = n;
        let mut alice = 10;
        let mut bob = 9;        
        let mut alice_turn = true;

        while n > 0 {
            if alice_turn {
                if n - alice < 0 { return false; }
                n -= alice;
                alice -= 2;
                alice_turn = !alice_turn;
            } else {
                if n - bob < 0 { return true; }
                n -= bob;
                bob -= 2;
                alice_turn = !alice_turn;
            }
        }

        !alice_turn
    }
}