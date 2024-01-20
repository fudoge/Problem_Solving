#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, int> indegree;

int check(int start)
{
    queue<int> q;
    q.push(start);

    bool isDoubleNext = false; // 한 번이라도 두 갈래로 나뉘는지
    bool isDonut = false;      // 도넛 모양이 생성되는지

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        auto next_node = graph[curr];
        if (next_node.size() > 1)
            return 3;
        for (const auto &nextNode : next_node)
        {
            if (nextNode == start)
                return 1;
            q.push(nextNode);
        }
    }

    return 2;

    int type;
    if (isDoubleNext && isDonut)
        type = 3;
    else if (isDonut)
        type = 1;
    else
        type = 2;

    return type;
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

    for (const auto &next : root_next)
    {
        int type = check(next);
        if (type != -1)
            answer[type]++;
    }

    return answer;
}