class Solution {
public:
    int getMaxLen(vector<int>& bars) {
        int r = 1;
        int i = 0;
        while(i < bars.size()) {
            int l = i;
            while(i+1 < bars.size() && bars[i] + 1 == bars[i+1]) {
                i++; 
            }
            r = max(r, i - l + 2);
            i++;
        }
        return r;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int h = getMaxLen(hBars);
        int v = getMaxLen(vBars);
        int side = min(h, v);

        return side * side;
    }
};