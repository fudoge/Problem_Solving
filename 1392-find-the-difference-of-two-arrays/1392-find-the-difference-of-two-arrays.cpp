class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    	vector<vector<int>> answer(2, vector<int>());
    
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        for (int num : set1) {
            if (!set2.count(num)) {
                answer.at(0).push_back(num);
            }
        }

        for (int num : set2) {
            if (!set1.count(num)) {
                answer.at(1).push_back(num);
            }
        }

        return answer;
    }
};