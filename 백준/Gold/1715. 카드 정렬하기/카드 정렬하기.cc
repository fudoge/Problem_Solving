#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    int sum = 0;
    while (pq.size() != 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + b;

        sum += c;
        pq.push(c);
    }

    cout << sum;
}