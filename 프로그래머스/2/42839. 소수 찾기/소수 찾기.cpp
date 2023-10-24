#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool _isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int n = numbers.length();
    vector<int> cards;
    set<int> nums;
    for (int i = 0; i < n; i++) {
        int num = static_cast<int>(numbers[i]);
        cards.push_back(num);
    }
    sort(cards.begin(), cards.end());
    do {
        string temp = "";
        for (int i = 0; i < n; i++) {
            temp.push_back(static_cast<char>(cards[i]));
            nums.insert(stoi(temp));
        }
    } while (next_permutation(cards.begin(), cards.end()));

    for (int num : nums) {
        if (_isPrime(num)) {
            answer++;
        }
    }

    return answer;
}
