class Solution {
public:
    int findComplement(int num) {
        return num ^ (ulong(1 << ulong(log2(num)) + 1) -1);
    }
};