#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ll w, h, f, c, x1, y1, x2, y2;
    cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
    ll ff = min(f, w-f);

    ll ans;
    if(ff < x1)
        ans = (c+1) * (y2-y1) * (x2-x1);
    else if(ff >= x1 && ff <= x2)
        ans = (c+1) * (y2-y1) * (2*(ff-x1) + (x2-ff));
    else
        ans = (c+1) * (y2-y1) * 2*(x2-x1);

    cout << w*h - ans << "\n";

    return 0;
}
