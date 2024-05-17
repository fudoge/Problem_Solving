class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int diff = 0;
        int curr_diff = 0;

        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size()-1; i++){
            curr_diff = arr[i] - arr[i+1];

            if(i == 0){
                diff = curr_diff;
                continue;
            } 
            if(curr_diff!= diff) return false;
        }

        return true;
    }
};