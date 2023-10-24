#include <bits/stdc++.h>

using namespace std;

char judge(char a, char b, unordered_map<char, int> &um) {
    if(um[a] > um[b]) {
        return a;
    } else if(um[a] < um[b]) {
        return b;
    } else {
        if(to_string(a) < to_string(b)) {
            return a;
        } else {
            return b;
        }
    }
}

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<char, int> um;
    string answer = "";
    vector<vector<char>> types = {
        {'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}
    };
    
    for(int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        int point;
        int target;
        if(choice == 4) continue;
        if(choice < 4) {
            point = 4-choice;
            target = 0;
        } else {
            point = choice-4;
            target = 1;
        }
        um[survey[i][target]]+=point;
    }
    
    for(const auto& type : types) {
        answer += judge(type[0], type[1], um);
    }
    
    return answer;
}