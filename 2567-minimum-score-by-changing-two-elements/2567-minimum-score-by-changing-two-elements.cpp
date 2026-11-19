// started_at: 09:12
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> cands;
        cout << *max_element(nums.begin(), nums.begin()+n-1);
        cands.push_back(*max_element(nums.begin()+2, nums.end()) - *min_element(nums.begin()+2, nums.end()));
        cands.push_back(*max_element(nums.begin()+1, nums.begin()+n-1) - *min_element(nums.begin()+1, nums.begin()+n-1));
        cands.push_back(*max_element(nums.begin(), nums.begin()+n-2) - *min_element(nums.begin(), nums.begin()+n-2));

        return *min_element(cands.begin(), cands.end());
    }
};
