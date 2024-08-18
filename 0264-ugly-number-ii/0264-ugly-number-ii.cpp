class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        arr[1] = 1;

        for(int i = 2; i < n+1; i++) {
            int i2ug = arr[i2] * 2;
            int i3ug = arr[i3] * 3;
            int i5ug = arr[i5] * 5;

            arr[i] = min(i2ug, min(i3ug, i5ug));
            
            if(arr[i] == i2ug) i2++;
            if(arr[i] == i3ug) i3++;
            if(arr[i] == i5ug) i5++;
        }

        return arr[n];
    }
};