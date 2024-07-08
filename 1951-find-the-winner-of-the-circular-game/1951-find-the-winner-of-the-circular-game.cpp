#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) {
            arr[i] = i+1;
        }

        int start = 0;
        k--;
        while(arr.size() > 1) {
            int idx = (start + k) % arr.size();
            arr.erase(arr.begin()+idx);
            start = idx;
        }
        return arr[0];
    }
};