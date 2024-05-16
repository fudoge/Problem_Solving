class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        do{
            sum += num % 10;
            num = num / 10;
        }while(num > 0);
        if (sum > 9){
            return addDigits(sum);
        }
        return sum;
    }
};