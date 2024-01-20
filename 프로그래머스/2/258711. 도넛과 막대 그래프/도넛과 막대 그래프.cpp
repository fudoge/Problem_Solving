#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, int> indegree;

int check(int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        auto next_node = graph[curr];
        if (next_node.size() > 1)
            return 3; // 8자 케이스
        for (const auto &nextNode : next_node)
        {
            if (nextNode == start)
                return 1; // 도넛 케이스
            q.push(nextNode);
        }
    }

    return 2; // 8자도 아니고, 도넛도 아니다? => 막대모양
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4, 0);

    for (const auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    int root;
    vector<int> root_next;
    // find root..
    for (const auto &g : graph)
    {
        if (!indegree[g.first] && g.second.size() > 1)
        {
            root = g.first;
            root_next = g.second;
            break;
        }
    }
    answer[0] = root;

    // 루트에서 이어진 정점에서 그래프 탐색 시작..
    for (const auto &next : root_next)
    {
        answer[check(next)]++;
    }

    return answer;
}