class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        deque<int> dq;
        vector<int> ans;
        int i;

        for(i = 0; i < deck.size()-1; i++) {
            dq.push_front(deck[i]);

            auto lastCard = dq.back();
            dq.pop_back();

            dq.push_front(lastCard);
        }
        dq.push_front(deck[i]);

        while(!dq.empty()) {
            auto card = dq.front();
            dq.pop_front();

            ans.push_back(card);
        }

        return ans;
    }
};