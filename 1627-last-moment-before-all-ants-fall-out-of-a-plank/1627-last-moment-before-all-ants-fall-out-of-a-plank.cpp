class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(left.size() == 0) return n - *min_element(right.begin(), right.end());
        if(right.size() == 0) return *max_element(left.begin(), left.end());
        int minleft = *max_element(left.begin(), left.end());
        int maxRight = n - *min_element(right.begin(), right.end());

        return max(minleft, maxRight);
    }
};