class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, bool> prefixes;
        for(int num : arr2) {
            while(num > 0) {
                prefixes[num] = true;
                num /= 10;
            }
        }
        
        int ans = 0;
        for(auto &num : arr1) {
            while(num > 0) {
                if(prefixes[num]) {
                    ans = max(ans, (int)log10(num) + 1);
                    break;
                }
                num /= 10;
            }
        }

        return ans;
    }
};