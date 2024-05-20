class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xor_sum = 0;
        for (int num : nums) {
            xor_sum |= num;  // 모든 숫자의 비트를 OR 연산합니다.
        }
        int n = nums.size();
        return xor_sum * (1 << (n - 1)); // 2^(n-1)을 곱합니다.
    }
};
