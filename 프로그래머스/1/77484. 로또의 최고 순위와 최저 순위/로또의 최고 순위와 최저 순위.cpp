#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> calcRank(int correct, int zero) {
    int maxCorrect = correct + zero;
    int minCorrect = correct;
    int maxRank = 0;
    int minRank = 0;

    maxRank = 7 - maxCorrect;
    minRank = 7 - minCorrect;


    if(maxRank >= 7) {
        maxRank = 6;
    }
    if(minRank >= 7) {
        minRank = 6;
    }
    return {maxRank, minRank};
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    const int n = lottos.size();
    const int m = win_nums.size();
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    

    int lottoIdx = 0;
    int win_numsIdx = 0;
    int amountOfZero = 0;
    int correct = 0;

    while(lottoIdx < n || win_numsIdx < m) {
        if(lottoIdx == n || win_numsIdx == m) {
            break;
        }

        if(lottos[lottoIdx] == 0) {
            amountOfZero++;
            lottoIdx++;
            continue;
        }
        if(lottos[lottoIdx] == win_nums[win_numsIdx]) {
            correct++;
            lottoIdx++;
            win_numsIdx++;
        } else if(lottos[lottoIdx] < win_nums[win_numsIdx]) {
            lottoIdx++;
        } else {
            win_numsIdx++;
        }
    }
    answer = calcRank(correct, amountOfZero);

    return answer;
}