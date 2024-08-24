class Solution {
public:
    bool isPalindrome(string n) {
        int left = 0;
        int right = n.size()-1;

        while(left < right) {
            if(n[left++] != n[right--]) return false;
        }
        return true;
    }
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        if(num <= 10) return to_string(num-1);
        if(num == 11) return "9";

        vector<string> ans;
        long long prefix = stoll(n.substr(0, (len+1)/2));

        vector<long long> candidates = {prefix-1, prefix, prefix+1};

        for(long long cand : candidates) {
            string candStr = to_string(cand);
            if(len%2) {
                candStr = candStr + string(candStr.rbegin()+1, candStr.rend());
            } else {
                candStr = candStr + string(candStr.rbegin(), candStr.rend());
            }
            ans.push_back(candStr);
        }

        ans.push_back("1" + string(len-1, '0') + "1");
        ans.push_back(string(len-1, '9'));

        string res;
        long long minDiff = LLONG_MAX;

        for (auto &cand : ans) {
            long long x = stoll(cand);
            if(x == num) continue;
            long long diff = abs(x - num);
            if(diff < minDiff || (diff == minDiff && x < stoll(res))) {
                res = cand;
                minDiff = diff;
            }
        }
        return res;
    }
};