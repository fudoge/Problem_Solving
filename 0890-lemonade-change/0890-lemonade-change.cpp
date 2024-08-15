class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twelve = 0;

        for(const auto &bill : bills) {
            if(bill == 20) twelve++;
            else if(bill == 10) ten++;
            else if(bill == 5) five++;

            int charge = bill - 5;
            while(charge > 0) {
                if(twelve && charge >= 20) {
                    charge -= 20;
                    twelve--;
                } else if(ten && charge >= 10) {
                    charge -= 10;
                    ten--;
                } else if(five && charge >= 5) {
                    charge -= 5;
                    five--;
                } else return false;
            }
        }

        return true;

        return true;
    }
};