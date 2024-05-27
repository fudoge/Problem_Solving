static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> mat;

        for(const auto &num : nums) {
            mp[num]++;
        }

        while(!mp.empty()) {
            vector<int> tmpArr;
            for(auto it = mp.begin(); it != mp.end(); ) {
                tmpArr.push_back(it -> first);
                it -> second--;
                if(it -> second == 0) {
                // erase후, 다음 iterator로 자동으로 넘어감
                    it = mp.erase(it);
                } else {
                // 다음 iterator로 넘어감
                    ++it;
                }
            }
            // 임시 배열을 행렬에 추가
            mat.push_back(tmpArr);
        }

        return mat;
    }
};