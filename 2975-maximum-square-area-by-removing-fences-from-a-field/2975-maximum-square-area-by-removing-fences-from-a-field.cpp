const int MOD = 1e9+7;
class Solution {
public:
    unordered_set<int> getIntervals(vector<int>& fences) {
        unordered_set<int> intervals;
        for(int i = 0; i < fences.size()-1; i++) {
            for(int j = i+1; j < fences.size(); j++) {
                intervals.insert(fences[j] - fences[i]);
            }
        }
        return intervals;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        
        unordered_set<int> hIntervals = getIntervals(hFences);
        unordered_set<int> vIntervals = getIntervals(vFences);
        
        vector<int> cand;
        for(int elem : hIntervals) {
            if(vIntervals.find(elem) != vIntervals.end()) {
                cand.push_back(elem);
            }
        }
        if(cand.empty()) return -1;
        sort(cand.begin(), cand.end());
        long long side = cand[cand.size()-1];

        return side * side % MOD;
    }
};