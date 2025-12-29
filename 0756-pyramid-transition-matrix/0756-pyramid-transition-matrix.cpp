class Solution {
public:
    int T[6][6];
    unordered_set<int> bad;
    int encode(vector<int> &v) {
        int x = 0;
        for(int n : v) {
            x = x * 6 + n;
        }
        return x;
    }
    bool dfs(vector<int> &bot) {
        if(bot.size() == 1) return true;

        vector<vector<int>> cand;
        vector<int> curr;
        generate(bot, 0, curr, cand);

        if(cand.empty()) {
            return false;
        }
        for(auto &c : cand) {
            int key = encode(c);
            if(bad.count(key)) continue;
            if(dfs(c)) return true;
        }

        bad.insert(encode(bot));
        return false;
    }
    void generate(vector<int> &bot, int idx, vector<int> &curr, vector<vector<int>>& cand) {
        if(idx == bot.size()-1) {
            cand.push_back(curr);
            return;
        }

        int left = bot[idx];
        int right = bot[idx+1];
        int mask = T[left][right];
        for(int c = 0; c < 6; c++) {
            if(mask & (1 << c)) {
                curr.push_back(c);
                generate(bot, idx+1, curr, cand);
                curr.pop_back();
            }
        }
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(const auto &a : allowed) {
            T[a[0]-'A'][a[1]-'A'] |= 1 << a[2] - 'A';
        } 
        vector<int> bot;
        for(char ch : bottom) {
            bot.push_back(ch - 'A');
        }
        return dfs(bot);
    }
};