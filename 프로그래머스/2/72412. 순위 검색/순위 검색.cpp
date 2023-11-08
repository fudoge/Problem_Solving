#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>> table;

void addCase(stringstream &ss) {
    string language, position, level, food, sc;
    int score;
    ss >> language >> position >> level >> food >> sc;
    score = stoi(sc);

    table[language + position + level + food].push_back(score);
    table["-" + position + level + food].push_back(score);
    table[language + "-" + level + food].push_back(score);
    table[language + position + "-" + food].push_back(score);
    table[language + position + level + "-"].push_back(score);
    table["--" + level + food].push_back(score);
    table["-" + position + "-" + food].push_back(score);
    table["-" + position + level + "-"].push_back(score);
    table[language + "--" + food].push_back(score);
    table[language + "-" + level + "-"].push_back(score);
    table[language + position + "--"].push_back(score);
    table["---" + food].push_back(score);
    table["--" + level + "-"].push_back(score);
    table["-" + position + "--"].push_back(score);
    table[language + "---"].push_back(score);
    table["----"].push_back(score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(const auto &participant_info : info) {
        stringstream ss(participant_info);
        addCase(ss);
    }
    for(const auto &t : table) {
        sort(table[t.first].begin(), table[t.first].end());
    }
    for(const auto &q: query) {
        stringstream ss(q);
        string str;
        string query_str = "";
        int acceptedScore = 0;
        while(ss >> str) {
            if(ss.eof()) {
                acceptedScore = stoi(str);
                break;
            }
            if(str != "and") {
                query_str += str;
            }
        }
        vector<int> scoreboard = table[query_str];
        // cout << query_str << ", ";
        // cout << acceptedScore << ", ";
        // for(const auto &num : scoreboard) {
        //     cout << num << " ";
        // }
        // cout << endl;
        auto it = lower_bound(scoreboard.begin(), scoreboard.end(), acceptedScore);
        answer.push_back(distance(it, scoreboard.end()));
    }
    
    return answer;
}
