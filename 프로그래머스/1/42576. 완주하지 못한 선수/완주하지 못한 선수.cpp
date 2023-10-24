#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> participant_map;

    for (const string& name : participant) {
        participant_map[name]++;
    }

    for (const string& name : completion) {
        participant_map[name]--;
    }

    for (const auto& entry : participant_map) {
        if (entry.second > 0) {
            return entry.first;
        }
    }

    return "";
}
