#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int left_deliveries = 0;
    int left_pickups = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        left_deliveries -= deliveries[i];
        left_pickups -= pickups[i];
        int cnt = 0;
        
        while (left_deliveries < 0 || left_pickups < 0) {
            
            left_deliveries += cap;
            left_pickups += cap;
            cnt++;
        }
        
        answer += (i + 1) * 2 * cnt;
    }
    return answer;
}
