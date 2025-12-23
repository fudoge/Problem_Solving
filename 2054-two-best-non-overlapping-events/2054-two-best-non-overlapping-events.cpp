class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        unordered_map<int, int> best;
        set<int> ends;
        sort(events.begin(), events.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        ends.insert(0);
        int ans = 0;
        for(const auto &event : events) {
            int s = event[0];
            int e = event[1];
            int v = event[2];

            auto lastEndIt = ends.lower_bound(s);
            if(lastEndIt != ends.begin()) {
                --lastEndIt;
            }
            int lastEnd = *lastEndIt;
            ans = max(ans, best[lastEnd] + v);

            ends.insert(e);
            best[e] = max(best[e], v);
            auto it = ends.lower_bound(e);
            if(it != ends.begin()) {
                --it;
            }
            best[e] = max(best[e], best[*it]);
        }

        return ans;
    }
};