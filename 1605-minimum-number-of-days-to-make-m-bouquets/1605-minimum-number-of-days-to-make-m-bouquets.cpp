class Solution {
private:
    int n;
public:
    bool check(vector<int>& bloomDay, int m, int k, int day) {
        int i = 0;
        int bouquets = 0;
        while (i < n) {
            int cnt = 0;
            while (i < n && cnt < k && bloomDay[i] <= day) {
                i++;
                cnt++;
            }
            if (cnt == k) bouquets++;
            if (bouquets == m) return true;
            while (i < n && bloomDay[i] > day) {
                i++;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};