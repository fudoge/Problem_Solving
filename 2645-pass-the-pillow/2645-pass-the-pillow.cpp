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