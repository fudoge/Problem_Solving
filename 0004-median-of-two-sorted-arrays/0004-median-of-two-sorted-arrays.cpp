class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        v.insert(v.end(), nums1.begin(), nums1.end());
        v.insert(v.end(), nums2.begin(), nums2.end());

        sort(v.begin(), v.end());

        if (v.size() % 2 == 1) {
            return v.at(v.size() / 2);
        }

        return (v.at(v.size() / 2 - 1) + v.at(v.size() / 2)) / 2.0;
    }
};