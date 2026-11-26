class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob = 9;
        bool aliceTurn = true;
        while(n > 0) {
            if(aliceTurn) {
                if(n - alice < 0) return false;
                n -= alice;
                alice -= 2;
                aliceTurn = !aliceTurn;
            } else {
                if(n - bob < 0) return true;
                n -= bob;
                bob -= 2;
                aliceTurn = !aliceTurn;
            }
        }

        return !aliceTurn;
    }
};