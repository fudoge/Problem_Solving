class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ;
        for(const auto &num : arr) {
            occ[num]++;
        }

        set<int> st;
        for(const auto & o : occ) {
            if(st.find(o.second) != st.end()) return false;
            st.insert(o.second);
        }

        return true;
    }
};