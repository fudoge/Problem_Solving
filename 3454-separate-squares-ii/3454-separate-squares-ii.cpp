using ll = long long;
class SegmentTree {
private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs;
    int n;

    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if(xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if(qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid+1, right, pos * 2 + 2);
        }

        if(count[pos] > 0) {
            covered[pos] = xs[right+1] - xs[left];
        } else {
            if(left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n-1, 0);
    }

    int query() { return covered[0]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<array<int, 4>> events;
        set<int> xsSet;
        for(const auto &square : squares) {
            int x = square[0];
            int y = square[1];
            int l = square[2];
            int xr = square[0] + l;
            events.push_back({y, 1, x, xr});
            events.push_back({y + l, -1, x, xr});
            xsSet.insert(x);
            xsSet.insert(xr);
        }
        sort(events.begin(), events.end());
        vector<int> xs(xsSet.begin(), xsSet.end());

        SegmentTree seg(xs);

        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = events[0][0];

        for (auto &e : events) {
            int y = e[0];
            int delta = e[1];
            int xl = e[2];
            int xr = e[3];

            int len = seg.query();
            total_area += 1LL * len * (y - prev);
            seg.update(xl, xr, delta);

            psum.push_back(total_area);
            widths.push_back(seg.query());
            prev = y;
        }

        ll target = (ll)(total_area + 1) / 2;
        int i = lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        double area = psum[i];
        int width = widths[i], height = events[i][0];

        return height + (total_area - area * 2) / (width * 2.0);
    }
};