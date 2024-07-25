class Solution {
public:
    void quicksort(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int mid = (left + right)/2;
        int pivot = nums[mid];
        int i = left;
        int j = right;

        while(i <= j) {
            while(nums[i] < pivot) i++;
            while(nums[j] > pivot) j--;
            if(i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        quicksort(nums, left, j);
        quicksort(nums, i, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};