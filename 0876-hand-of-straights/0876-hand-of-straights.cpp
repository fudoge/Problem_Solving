class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) {
            return false;
        }
        
        unordered_map<int, int> freq;
        for(const auto &card : hand) {
            freq[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto element : freq) {
            pq.push(element.first);
        }

        while(!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            freq[curr]--;
            

            for(int i = 1; i < groupSize; i++) {
                if(pq.top() != curr+1) return false;

                curr++;
                pq.pop();
                freq[curr]--;
            }

            for(int i = 0; i < groupSize; i++) {
                if(freq[curr - i] > 0) pq.push(curr - i);
            }
        }

        return true;
    }
};