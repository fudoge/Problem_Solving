class Solution {
   public:
    int smallestNumber(int n) {
        int exp = log2(n);

        return (1 << (exp + 1)) - 1;
    }
};