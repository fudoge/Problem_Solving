class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int n = arr.size();
        int peakIndex = -1;
        int peakHeight = -1;

        for(int i = 0; i < n; i++){
            if(arr[i] > peakHeight){
                peakHeight = arr[i];
                peakIndex = i;
            }
            else{
                break;
            }
        }
        return peakIndex;
    }
};