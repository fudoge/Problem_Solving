#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(const auto &bill : bills) {
            if(bill == 10) ten++;
            else if(bill == 5) five++;

            int charge = bill - 5;
            while(charge > 0) {
                if(ten && charge >= 10) {
                    charge -= 10;
                    ten--;
                } else if(five && charge >= 5) {
                    charge -= 5;
                    five--;
                } else return false;
            }
        }

        return true;
    }
};