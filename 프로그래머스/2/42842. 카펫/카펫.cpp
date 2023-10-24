#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;  // 전체 격자의 개수

    vector<int> answer;

    for (int i = 1; i <= total; i++) {
        if (total % i == 0) {
            const int width = i;
            const int length = total / i;

            if ((width - 2) * (length - 2) == yellow) {
                answer.push_back(length);
                answer.push_back(width);
                break;
            }
        }
    }

    return answer;
}
