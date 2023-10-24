#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    int length = number.length();
    int remain = length - k;
    string answer = "";

    int start = 0;
    while (remain > 0) {
        char maxNum = number[start];
        int idx = start;

        for (int i = start + 1; i <= length - remain; i++) {
            if (number[i] > maxNum) {
                maxNum = number[i];
                idx = i;
            }
        }

        answer += maxNum;
        start = idx + 1;
        remain--;
    }

    return answer;
}