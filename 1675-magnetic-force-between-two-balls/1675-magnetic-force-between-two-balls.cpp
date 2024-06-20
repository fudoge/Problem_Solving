class Solution {
    int n;
public:
    int isAble(int dist, int m, vector<int>& position) {
        int balls = 1;
        int last = position[0];
        for(int i = 1; i < n; i++) {
            if(position[i] - last >= dist) {
                balls++;
                last = position[i];
            }
            if(balls >= m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        n = position.size();
        sort(position.begin(), position.end());
        int low = 1;
        int high = (position[n-1] - position[0]) / (m-1);
        int ans = 0;
        while(low <= high) {
            int mid = (low + high)/2;
            if(isAble(mid, m, position)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};