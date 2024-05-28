class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        int left = 0;
        int cost = 0;

        for(int right = 0; right < n; right++) {
            cost += abs(s[right] - t[right]);
            while(cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};