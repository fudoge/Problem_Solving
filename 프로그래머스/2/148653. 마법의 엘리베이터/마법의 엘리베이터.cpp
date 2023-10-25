#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int cnt = 0;
    while(storey > 0) {
        int digit = storey % 10;
        storey /= 10;
        
        if(digit >= 6) {
            cnt += 10-digit;
            storey++;
        } else if(digit == 5) {
            int digit2 = storey % 10;
            if(digit2 >= 5) {
                cnt += 5;
                storey++;
            } else {
                cnt+= 5;
            }
        } else {
            cnt += digit;
        }
    }
    return cnt;
}