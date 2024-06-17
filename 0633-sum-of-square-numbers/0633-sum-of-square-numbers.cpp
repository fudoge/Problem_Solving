class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 1, b = sqrt(c);

        if(b*b == c) return true;
        while(a <= b) {
            long long sum = a*a + b*b;
            if(sum == c) return true;
            else if(sum > c) {
                b--;
            } else {
                a++;
            }
        }

        return false;
    }
};