class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        long long ans = 0;

        while(left < right) {
            while(left < right && s[left] == '0') left++;
            while(left < right && s[right] == '1') right--;

            ans += right - left;
            swap(s[left], s[right]);
        }

        return ans;
    }
};