#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> location = {
    {3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2},
    {2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 2}
};

int calc_distance(pair<int, int> from, pair<int, int> to) {
    return abs(from.first - to.first) + abs(from.second - to.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> Llocation = location[10];
    pair<int, int> Rlocation = location[11];

    for(const auto& num : numbers) {
        if(num == 1 || num == 4 || num == 7) {
            answer += 'L';
            Llocation = location[num];
        } else if(num == 3 || num == 6 || num == 9) {
            answer += 'R';
            Rlocation = location[num];
        } else {
            int Ldistance = calc_distance(Llocation, location[num]);
            int Rdistance = calc_distance(Rlocation, location[num]);
            if(Ldistance == Rdistance) {
                if(hand == "right") {
                    answer += 'R';
                    Rlocation = location[num];
                } else {
                    answer += 'L';
                    Llocation = location[num];
                }
            } else if(Ldistance < Rdistance) {
                answer += 'L';
                Llocation = location[num];
            } else {
                answer += 'R';
                Rlocation = location[num];
            }
        }
    }
    
    return answer;
}