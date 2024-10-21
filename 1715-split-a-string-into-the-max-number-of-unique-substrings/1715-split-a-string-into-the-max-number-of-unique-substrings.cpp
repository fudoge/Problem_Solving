class Solution {
private:
    int ans;
    int n;
    unordered_map<string, int> exists;
    void solve(int idx, int count, string &s) {
        if(idx >= n) {
            ans = max(ans, count);
        }

        string temp = string(1, s[idx]);
        for(int i = idx+1; i <= n; ++i) {
            cout << i << " " << temp << endl;
            if(exists[temp] == 0) {
                exists[temp]++;
                solve(i, count+1, s);
                exists[temp]--;
            }
            temp += s[i];
        }
    }
public:
    int maxUniqueSplit(string s) {
        n = s.size();
        solve(0, 0, s);
        return ans;
    }
};