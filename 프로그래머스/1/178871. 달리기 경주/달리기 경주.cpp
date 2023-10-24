#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    const int n = players.size();
    vector<string> answer;
    unordered_map<string, int> playerToIndex;

    for (int i = 0; i < n; i++) {
        playerToIndex[players[i]] = i;
    }

    for (const auto& call : callings) {
        int idx = playerToIndex[call];
        if (idx > 0) {
            swap(players[idx], players[idx - 1]);
            playerToIndex[call] = idx - 1;
            playerToIndex[players[idx]] = idx;
        }
    }

    return players;
}
