#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        unordered_map<int, int> best;
        vector<int> ends = {0};
        sort(events.begin(), events.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        int ans = 0;
        for(const auto &event : events) {
            int s = event[0];
            int e = event[1];
            int v = event[2];

            auto lastEndIt = lower_bound(ends.begin(), ends.end(), s);
            if(lastEndIt != ends.begin()) { --lastEndIt; }
            int lastEnd = *lastEndIt;
            ans = max(ans, best[lastEnd] + v);

            if(ends.back() != e) { ends.emplace_back(e); }
            best[e] = max(best[e], v);
            best[e] = max(best[e], best[ends[ends.size()-2]]);
        }

        return ans;
    }
};