#include <bits/stdc++.h>
#define LIMIT 30000

using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> points;

// Function to check if two squares of size 'len' can cover all points
bool check(int len, pii &p1, pii &p2) {
    // Iterate through all points to try as the base for the first square
    for(auto &base : points){
        // Possible positions for the first square's bottom-left corner
        // Offset by 0 or -len to ensure the base point is included within the square
        vector<pii> first_square_positions = {
            {base.first, base.second},
            {base.first - len, base.second},
            {base.first, base.second - len},
            {base.first - len, base.second - len}
        };
        
        for(auto &pos1 : first_square_positions){
            int x1 = pos1.first;
            int y1 = pos1.second;
            int right1 = x1 + len;
            int top1 = y1 + len;
            
            // Collect points not covered by the first square
            vector<pii> outBounds;
            int newMinX = LIMIT, newMinY = LIMIT;
            for(auto &p : points){
                if(!(p.first >= x1 && p.first <= right1 &&
                     p.second >= y1 && p.second <= top1)){
                    outBounds.emplace_back(p);
                    newMinX = min(newMinX, p.first);
                    newMinY = min(newMinY, p.second);
                }
            }
            
            // If all points are covered by the first square
            if(outBounds.empty()){
                p1 = {x1, y1};
                p2 = {x1, y1};
                return true;
            }
            
            // Place the second square at (newMinX, newMinY)
            // which is the bottom-left most point among the remaining points
            int x2 = newMinX;
            int y2 = newMinY;
            int right2 = x2 + len;
            int top2 = y2 + len;
            
            bool all_covered = true;
            for(auto &p : outBounds){
                if(!(p.first >= x2 && p.first <= right2 &&
                     p.second >= y2 && p.second <= top2)){
                    all_covered = false;
                    break;
                }
            }
            
            if(all_covered){
                p1 = {x1, y1};
                p2 = {x2, y2};
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    points.resize(n);
    int x, y;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        points[i] = {x, y};
    }
    
    // Binary search to find the minimal 'len'
    int left = 0;
    int right = 2 * LIMIT; // Maximum possible len
    int result_len = right;
    pii result_p1, result_p2;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        pii temp_p1, temp_p2;
        if(check(mid, temp_p1, temp_p2)){
            // If possible, try to find a smaller len
            result_len = mid;
            result_p1 = temp_p1;
            result_p2 = temp_p2;
            right = mid - 1;
        }
        else{
            // If not possible, increase len
            left = mid + 1;
        }
    }
    
    // Output the result
    cout << result_len << "\n";
    cout << result_p1.first << " " << result_p1.second << "\n";
    cout << result_p2.first << " " << result_p2.second << "\n";
    
    return 0;
}