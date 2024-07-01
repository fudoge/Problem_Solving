class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int streak = 0;
        for(const auto& x : arr) {
            if(x%2 == 1) {
                if(++streak == 3) return true;
            } else {
                streak = 0;
            }
    
        }
        return false;
    }
};