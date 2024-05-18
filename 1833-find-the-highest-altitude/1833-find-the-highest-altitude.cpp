class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int answer = 0;
        int current_height = 0;
        for(int i = 0; i < gain.size(); i++){
            current_height += gain[i];
            answer = max(current_height, answer);
        }
        return answer;
    }
};