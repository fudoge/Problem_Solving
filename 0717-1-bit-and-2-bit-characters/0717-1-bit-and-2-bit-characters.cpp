class Solution {
   public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        for (int i = 0; i < n; i++) {
            bool flag = false;
            if (bits[i] == 1) {
                i++;
                flag = true;
            }
            if (i == n - 1 && flag) {
                return false;
            }
        }

        return true;
    }
};