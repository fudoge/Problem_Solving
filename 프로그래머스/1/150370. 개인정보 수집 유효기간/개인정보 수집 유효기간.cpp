#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void calc_validate(unordered_map<char, int> &um, string privacy, vector<int> &dueDates) {
    int dueYear = stoi(privacy.substr(0, 4));
    int dueMonth = stoi(privacy.substr(5, 2));
    int dueDate = stoi(privacy.substr(8, 2));
    char term = privacy[privacy.size() - 1];

    dueMonth += um[term];
    dueDate -= 1;
    
    int newDue = dueYear * 12 * 28 + dueMonth * 28 + dueDate;
    dueDates.push_back(newDue);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> um;
    for (auto term : terms) {
        char t = term[0];
        int due = stoi(term.substr(2, term.size() - 2));
        um[t] = due;
    }
    vector<int> dueDates;
    
    int todayYear = stoi(today.substr(0, 4));
    int todayMonth = stoi(today.substr(5, 2));
    int todayDate = stoi(today.substr(8, 2));
    int todayNum = todayYear * 12 * 28 + todayMonth * 28 + todayDate;

    for (int i = 0; i < privacies.size(); i++) {
        calc_validate(um, privacies[i], dueDates);
        int dueDate = dueDates[i];
        if(todayNum > dueDate) {
            answer.push_back(i+1);
        }
    }

    return answer;
}