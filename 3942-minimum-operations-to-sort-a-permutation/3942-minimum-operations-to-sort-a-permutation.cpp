
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool isAsc = true;
        bool isDesc = true;
        int zeroIdx = -1;
        int maxIdx = -1;

        for (int i = 0; i < n; i++) {
            int next = nums[(i + 1) % n];

            if (next != (nums[i] + 1) % n)
                isAsc = false;

            if (next != (nums[i] + n - 1) % n)
                isDesc = false;

            if (nums[i] == 0)
                zeroIdx = i;

            if (nums[i] == n - 1)
                maxIdx = i;
        }

        int ans = INT_MAX;

        if (isAsc) {
            // Rotate left
            int left = zeroIdx;

            // Reverse -> Rotate left -> Reverse
            int right = (n - zeroIdx) % n + 2;

            ans = min(ans, min(left, right));
        }

        if (isDesc) {
            // Rotate left -> Reverse
            int rotateFirst = maxIdx + 1;

            // Reverse -> Rotate left
            int reverseFirst = n - zeroIdx;

            ans = min(ans, min(rotateFirst, reverseFirst));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
