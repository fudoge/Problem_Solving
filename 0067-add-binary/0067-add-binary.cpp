class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        int carry = 0;
        string ans = "";
        while(i < a.size() || i < b.size()) {
            int A = i >= a.size() ? 0 : a[i] == '0' ? 0 : 1;
            int B = i >= b.size() ? 0 : b[i] == '0' ? 0 : 1;

            int sum = A + B + carry;
            if(sum >= 2) {
                sum -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans += '0' + sum;
            i++;
        }
        if(carry == 1) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};