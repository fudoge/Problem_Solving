class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = ((len+1)/2);

        if(k == mid) return '1';
        else if(k < mid) {
            return findKthBit(n-1, k);
        } else {
            char res = findKthBit(n-1, 2*mid-k);
            if(res == '0') res = '1';
            else res = '0';
            return res;
        }
    }
};