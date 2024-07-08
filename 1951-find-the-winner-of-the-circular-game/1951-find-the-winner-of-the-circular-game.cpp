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
        queue<int> q;

        for(int i = 1; i <= n; i++) {
            q.push(i);
        }

        while(q.size() > 1) {
            for(int i = 1; i < k; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};