#include <bits/stdc++.h>

using namespace std;

struct Coordinate {
  int x;
  int y;
  int z;
  Coordinate(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
};

int getRoot(int x, vector<int> &parent) {
  if (parent[x] == -1)
    return x;
  return parent[x] = getRoot(parent[x], parent);
}

bool merge(int u, int v, vector<int> &parent) {
  int uRoot = getRoot(u, parent);
  int vRoot = getRoot(v, parent);

  if (uRoot == vRoot)
    return false;
  else if (uRoot < vRoot)
    parent[vRoot] = uRoot;
  else
    parent[uRoot] = vRoot;

  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<Coordinate *> arr(n);
  vector<int> xPoses(n);
  vector<int> yPoses(n);
  vector<int> zPoses(n);
  unordered_map<int, vector<int>> xPosToCID;
  unordered_map<int, vector<int>> yPosToCID;
  unordered_map<int, vector<int>> zPosToCID;
  vector<int> parent(n, -1);

  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    auto C = new Coordinate(x, y, z);
    arr[i] = C;
    xPoses[i] = x;
    yPoses[i] = y;
    zPoses[i] = z;
    xPosToCID[x].emplace_back(i);
    yPosToCID[y].emplace_back(i);
    zPosToCID[z].emplace_back(i);
  }

  sort(xPoses.begin(), xPoses.end());
  sort(yPoses.begin(), yPoses.end());
  sort(zPoses.begin(), zPoses.end());
  xPoses.erase(unique(xPoses.begin(), xPoses.end()), xPoses.end());
  yPoses.erase(unique(yPoses.begin(), yPoses.end()), yPoses.end());
  zPoses.erase(unique(zPoses.begin(), zPoses.end()), zPoses.end());

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq; // dist, src_id, dst_id
  long long ans = 0;

  auto f = [&](int u) {
    int rankX =
        lower_bound(xPoses.begin(), xPoses.end(), arr[u]->x) - xPoses.begin();
    int rankY =
        lower_bound(yPoses.begin(), yPoses.end(), arr[u]->y) - yPoses.begin();
    int rankZ =
        lower_bound(zPoses.begin(), zPoses.end(), arr[u]->z) - zPoses.begin();

    for (int i = 0; i < xPosToCID[xPoses[rankX]].size(); ++i) {
      int v = xPosToCID[xPoses[rankX]][i];
      if (getRoot(u, parent) != getRoot(v, parent))
        pq.push(make_tuple(0, u, v));
    }

    if (rankX > 0) {
      for (int i = 0; i < xPosToCID[xPoses[rankX - 1]].size(); ++i) {
        int v = xPosToCID[xPoses[rankX - 1]][i];
        int w = min({abs(arr[u]->x - arr[v]->x), abs(arr[u]->y - arr[v]->y),
                     abs(arr[u]->z - arr[v]->z)});
        if (getRoot(u, parent) != getRoot(v, parent))
          pq.push(make_tuple(w, u, v));
      }
    }

    if (rankX < xPoses.size() - 1) {
      for (int i = 0; i < xPosToCID[xPoses[rankX + 1]].size(); ++i) {
        int v = xPosToCID[xPoses[rankX + 1]][i];
        int w = min({abs(arr[u]->x - arr[v]->x), abs(arr[u]->y - arr[v]->y),
                     abs(arr[u]->z - arr[v]->z)});
        if (getRoot(u, parent) != getRoot(v, parent))
          pq.push(make_tuple(w, u, v));
      }
    }

    for (int i = 0; i < yPosToCID[yPoses[rankY]].size(); ++i) {
      int v = yPosToCID[yPoses[rankY]][i];
      if (getRoot(u, parent) != getRoot(v, parent))
        pq.push(make_tuple(0, u, v));
    }

    if (rankY > 0) {
      for (int i = 0; i < yPosToCID[yPoses[rankY - 1]].size(); ++i) {
        int v = yPosToCID[yPoses[rankY - 1]][i];
        int w = min({abs(arr[u]->x - arr[v]->x), abs(arr[u]->y - arr[v]->y),
                     abs(arr[u]->z - arr[v]->z)});
        if (getRoot(u, parent) != getRoot(v, parent))
          pq.push(make_tuple(w, u, v));
      }
    }

    if (rankY < yPoses.size() - 1) {
      for (int i = 0; i < yPosToCID[yPoses[rankY + 1]].size(); ++i) {
        int v = yPosToCID[yPoses[rankY + 1]][i];
        int w = min({abs(arr[u]->x - arr[v]->x), abs(arr[u]->y - arr[v]->y),
                     abs(arr[u]->z - arr[v]->z)});
        if (getRoot(u, parent) != getRoot(v, parent))
          pq.push(make_tuple(w, u, v));
      }
    }

    for (int i = 0; i < zPosToCID[zPoses[rankZ]].size(); ++i) {
      int v = zPosToCID[zPoses[rankZ]][i];
      if (getRoot(u, parent) != getRoot(v, parent))
        pq.push(make_tuple(0, u, v));
    }

    if (rankZ > 0) {
      for (int i = 0; i < zPosToCID[zPoses[rankZ - 1]].size(); ++i) {
        int v = zPosToCID[zPoses[rankZ - 1]][i];
        int w = min({abs(arr[u]->x - arr[v]->x), abs(arr[u]->y - arr[v]->y),
                     abs(arr[u]->z - arr[v]->z)});
        if (getRoot(u, parent) != getRoot(v, parent))
          pq.push(make_tuple(w, u, v));
      }
    }

    if (rankZ < zPoses.size() - 1) {
      for (int i = 0; i < zPosToCID[zPoses[rankZ + 1]].size(); ++i) {
        int v = zPosToCID[zPoses[rankZ + 1]][i];
        int w = min({abs(arr[u]->x - arr[v]->x), abs(arr[u]->y - arr[v]->y),
                     abs(arr[u]->z - arr[v]->z)});
        if (getRoot(u, parent) != getRoot(v, parent))
          pq.push(make_tuple(w, u, v));
      }
    }
  };

  f(0);

  for (int it = 0; it < n - 1; ++it) {
    while (true) {
      int w, u, v;
      tie(w, u, v) = pq.top();
      pq.pop();

      if (merge(u, v, parent)) {
        ans += w;
        f(v);
        break;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}