#include <iostream>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    int minMove = length - 1;

    for (int i = 0; i < length; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        int nextPos = i + 1;

        while (nextPos < length && name[nextPos] == 'A')
            nextPos++;

        minMove = min(minMove, i + length - nextPos + min(i, length - nextPos));
    }

    answer += minMove;

    return answer;
}