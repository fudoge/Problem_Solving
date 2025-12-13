class Solution {
public:
    vector<string> addCoupon(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive, string& acceptBL) {
        vector<string> res;
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
            if(businessLine[i] != acceptBL) continue;
            if(!isActive[i]) continue;
            res.emplace_back(code[i]);
        } 

        return res;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        vector<string> acceptBLs = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(auto &abl : acceptBLs) {
            auto res = addCoupon(code, businessLine, isActive, abl);
            sort(res.begin(), res.end());
            for(string &s : res) {
                ans.emplace_back(s);
            }
        }

        return ans;
    }
};