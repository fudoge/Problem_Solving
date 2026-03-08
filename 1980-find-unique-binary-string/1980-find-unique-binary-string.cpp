class Solution {
private:
    int n;
    unordered_set<string> s;
    string ans;
    bool dfs(string str) {
        if(str.size() == n) {
            if(s.find(str) == s.end()) {
                ans = str;
                return true;
            }
            return false;
        }

        if(dfs(str + '0')) return true;
        if(dfs(str + '1')) return true;
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].size();
        for(const auto &num : nums) {
            s.insert(num);
        }
        // start with 0..
        if(dfs("0")) return ans;
        // start with 1..
        if(dfs("1")) return ans;
        return "";
    }
};