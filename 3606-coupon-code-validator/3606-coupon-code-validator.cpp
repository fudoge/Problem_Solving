#pragma GCC optimize("O3", "unroll-loops");
static const int __ == [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> level = {
            { "electronics", 1 },
            { "grocery", 2 },
            { "pharmacy", 3 },
            { "restaurant", 4 },
        };
        vector<string> ans;
        vector<vector<string>> coupons;
        for(int i = 0; i < code.size(); i++) {
            if(code[i].size() < 1) {
                continue;
            }
            bool flag = false;
            for(const char &c : code[i]) {
                if(!(isalnum(c) || c == '_')) {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            if(!level[businessLine[i]]) continue;
            if(!isActive[i]) continue;
            coupons.push_back({code[i], businessLine[i]});
        } 

        sort(coupons.begin(), coupons.end(), [&](const auto &a, const auto &b){
            int la = level[a[1]];
            int lb = level[b[1]];
            if(la == lb) {
                return a[0] < b[0];
            }
            return la < lb;
        });

        for(auto c : coupons) {
            ans.emplace_back(c[0]);
        }

        return ans;
    }
};