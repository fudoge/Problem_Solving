#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++) {
            int num = i;
            int next = i+1;
			
            // 현재 숫자가 범위 내에 있고, 다음 붙을 숫자가 유효한 동안
            while(num <= high && next <= 9) {
                num = num*10 + next;
                if(num >= low && num <= high) ans.push_back(num);
                next++;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};