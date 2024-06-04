#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        const int m = nums2.size();
        int i = 0, j = 0;

        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) return nums1[i];

            if(nums1[i] > nums2[j]) j++;
            else i++;
        }

        return -1;
    }
};