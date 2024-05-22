class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int n = s.size();

        while (left < n) {
            if (s[left] == ' ')
                left++;
            int right = left;

            while (right < n && s[right] != ' ') {
                right++;
                
            }
            right--;

            int start = left, end = right;
            while (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }

            left = right + 2;
        }
        return s;
    }
};