#include <vector>
#include <queue>

using namespace std;

vector<int> calculateFares(int start, vector<vector<pair<int, int>>> &graph, int n)
{
    vector<int> distance(n + 1, 123456789);
    distance[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (const auto &next : graph[curr])
        {
            int nextNode = next.first;
            int nextCost = next.second;
            if (distance[nextNode] > distance[curr] + nextCost)
            {
                distance[nextNode] = distance[curr] + nextCost;
                q.push(nextNode);
            }
        }
    }

    return distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 123456789;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (const auto &fare : fares)
    {
        int start = fare[0];
        int end = fare[1];
        int cost = fare[2];

        graph[start].push_back({end, cost});
        graph[end].push_back({start, cost});
    }

    vector<int> commonFares = calculateFares(s, graph, n);
    vector<int> aFares = calculateFares(a, graph, n);
    vector<int> bFares = calculateFares(b, graph, n);

    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, commonFares[i] + aFares[i] + bFares[i]);
    }

    return answer;
}