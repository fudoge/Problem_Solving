#include <string>
#include <vector>

using namespace std;
int answer = 0;

void getTarget(vector<int>& numbers, int target, int sum, int index) {
    if(index == numbers.size()) {
        if(sum == target) {
            answer++;
        }
        return;
    } else {
        getTarget(numbers, target, sum + numbers[index], index+1);
        getTarget(numbers, target, sum - numbers[index], index+1);
    }
}

int solution(vector<int> numbers, int target) {
    getTarget(numbers, target, 0, 0);
    return answer;
}
