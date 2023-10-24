#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> snail(n, vector<int>(n, 0));
    
    int max_num = n * (n + 1) / 2;
    int num = 1;
    int row = 0, col = 0;
    
    while (num <= max_num) {
        while (row < n && snail[row][col] == 0) {
            snail[row++][col] = num++;
        }
        row--;
        col++;
        
        while (col < n && snail[row][col] == 0) {
            snail[row][col++] = num++;
        }
        col -= 2;
        row--;
        
        while (row >= 0 && col >= 0 && snail[row][col] == 0) {
            snail[row--][col--] = num++;
        }
        row += 2;
        col++;
    }
    
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(snail[i][j]);
        }
    }
    
    return answer;
}
