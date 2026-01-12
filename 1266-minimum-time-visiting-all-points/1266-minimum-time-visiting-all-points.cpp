class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            int xdiff = abs(points[i+1][0] - points[i][0]);
            int ydiff = abs(points[i+1][1] - points[i][1]);
            ans += max(xdiff, ydiff);
        }       

        return ans;
    }
};