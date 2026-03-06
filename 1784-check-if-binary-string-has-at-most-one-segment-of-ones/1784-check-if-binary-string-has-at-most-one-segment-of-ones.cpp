class Solution {
public:
    bool checkOnesSegment(string s) {
        int seg = 0;
        int last = 0;

        for(char ch : s) {
            int c = ch - '0';
            if(c==1) {
                if(last == 0) seg++;
            }
            last = c;
        }

        return seg <= 1;
    }
};