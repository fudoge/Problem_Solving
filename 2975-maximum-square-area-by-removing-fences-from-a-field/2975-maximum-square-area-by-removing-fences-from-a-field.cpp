#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
const int MOD = 1e9+7;
class Solution {
public:
    vector<int> getIntervals(vector<int>& fences) {
        vector<int> intervals;
        for(int i = 0; i < fences.size()-1; i++) {
            for(int j = i+1; j < fences.size(); j++) {
                intervals.emplace_back(fences[j] - fences[i]);
            }
        }
        sort(intervals.begin(), intervals.end());
        intervals.erase(unique(intervals.begin(), intervals.end()), intervals.end());
        return intervals;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.emplace_back(1);
        hFences.emplace_back(m);
        vFences.emplace_back(1);
        vFences.emplace_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        
        vector<int> hIntervals = getIntervals(hFences);
        vector<int> vIntervals = getIntervals(vFences);
        
        long long side = -1;
        for(const auto &elem : hIntervals) {
            auto it = lower_bound(vIntervals.begin(), vIntervals.end(), elem) - vIntervals.begin();
            if(vIntervals[it] == elem) side = max(side, (long long)elem);
        }
        if(side == -1) return -1;
        return side * side % MOD;
    }
};