#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int idx = 0; idx < commands.size(); idx++) {
        const int i = commands[idx][0] - 1;
        const int j = commands[idx][1] - 1;
        const int k = commands[idx][2] - 1;
        vector<int> arr(array.begin() + i, array.begin() + j + 1);
        sort(arr.begin(), arr.end());
        answer.push_back(arr[k]);
    }
    return answer;
}
