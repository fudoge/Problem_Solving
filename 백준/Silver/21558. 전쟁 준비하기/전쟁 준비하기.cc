#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> soldiers(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> soldiers[i];
        sum += soldiers[i];
    }

    vector<int> divisors;
    for (int i = 1; i * i <= sum; ++i)
    {
        if (sum % i == 0)
        {
            divisors.push_back(i);
            if (i != sum / i)
                divisors.push_back(sum / i);
        }
    }
    sort(divisors.begin(), divisors.end(), greater<int>());

    vector<int> group_list;
    for (int i = 0; i < n; ++i)
    {
        group_list.insert(group_list.end(), soldiers[i], i);
    }

    vector<pair<int, int>> fights_Y;
    for (int Y : divisors)
    {
        int fights = 0;
        int M = sum;
        int H = M / Y;
        for (int r = 0; r < H; ++r)
        {
            for (int c = 0; c < Y - 1; ++c)
            {
                int idx1 = r * Y + c;
                int idx2 = idx1 + 1;
                if (group_list[idx1] != group_list[idx2])
                    fights++;
            }
        }
        fights_Y.push_back({fights, Y});
    }

    vector<int> max_Y(n, 0);
    for (int k = 0; k < n; ++k)
        max_Y[k] = 0;

    for (auto &fy : fights_Y)
    {
        int fights = fy.first;
        int Y = fy.second;
        for (int k = fights; k < n; ++k)
        {
            max_Y[k] = max(max_Y[k], Y);
        }
    }

    for (int k = 0; k < n; ++k)
    {
        cout << max_Y[k] << " ";
    }
    cout << "\n";

    return 0;
}