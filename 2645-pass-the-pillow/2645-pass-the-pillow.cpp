#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int passThePillow(int n, int time) {
        int pillow = 1;
        bool dirFlag = true;

        while(time > 0) {
            if(dirFlag) {
                pillow++;
                if(pillow == n) dirFlag = !dirFlag;
            } else {
                pillow--;
                if(pillow == 1) dirFlag = !dirFlag;
            }
            time--;
        }

        return pillow;
    }
};