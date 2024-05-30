class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> prefix(n+1, 0);
        for(int i = 1; i < n+1; i++) {
            prefix[i] = prefix[i-1] ^ arr[i-1];
        }

        for(int i = 0; i < n; i++) {
            for(int k = i+1; k < n; k++) {
                if(prefix[i] == prefix[k+1]) ans += k-i;
            }
        }

        return ans;
    }
};