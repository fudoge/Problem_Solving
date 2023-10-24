#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (const auto& number : numbers) {
        if (number % 2 == 0) {
            answer.push_back(number + 1);
        }
        else {
            long long num = 2;
            long long x = number - 1;
            while(x <= number) {
                x = number ^ num;
                if (x < number) {
                    x ^= num;  
                    num *= 2;    
                }
                else {
                    x ^= num / 2;
                }
            }
            answer.push_back(x);
        }
    }
    
    return answer;
}