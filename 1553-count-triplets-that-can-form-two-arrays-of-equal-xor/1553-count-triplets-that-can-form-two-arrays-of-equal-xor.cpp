class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int length = 2;

        while(length <= n) {
            for(int start = 0; start <= n - length; start++) {
                int a = 0, b, i;
                for(i = start; i < start + length - 1; i++) {
                    a ^= arr[i];
                }
                b = arr[i];

                // cout << a << "(a) " << b << "(b) " << start << "(i) " << i << "(j) " << start + length -1 << "(k)\n";
                if(a == b) ans++;
                for(i = i-1; i > start; i--) {
                    a ^= arr[i];
                    b ^= arr[i];
                    if(a == b) ans++;
                    // cout << a << "(a) " << b << "(b) " << start << "(i) " << i << "(j) " << start + length -1 << "(k)\n";
                }
            }
            length++;
            // cout << endl;
        }

        return ans;
    }
};