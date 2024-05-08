struct comp {
    bool operator()(const auto &a, const auto &b){
        return a.first < b.first;
    };
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        int cnt = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if(cnt >= 3) {
                ans[curr.second] = to_string(cnt+1);
            } else if (cnt == 2) {
                ans[curr.second] = "Bronze Medal";
            } else if (cnt == 1) {
                ans[curr.second] = "Silver Medal";
            } else {
                ans[curr.second] = "Gold Medal";
            }
            cnt++;
        }

        return ans;
    }
};