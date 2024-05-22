class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(const auto& num : nums) {
            pq.push(num);
        }

        int longest = 0;
        while(!pq.empty()) {
            vector<int> sequence;
            while(!pq.empty()) {
                if(sequence.size() == 0) {
                    sequence.push_back(pq.top());
                    pq.pop();
                    continue;
                }
                if(sequence[sequence.size()-1] == pq.top()) {
                    pq.pop();
                } else if(sequence[sequence.size()-1]+1 == pq.top()) {
                    sequence.push_back(pq.top());
                    pq.pop();
                } else {
                    break;
                }
            }
            longest = max(longest, static_cast<int>(sequence.size()));
        }
        return longest;
    }
};