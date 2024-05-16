class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        priority_queue<int> q;
        for (int i = 0; i < salary.size(); i++){
            q.push(salary.at(i));
        }
        q.pop();
        for (int i = 0; i < salary.size()-2; i++){
            sum += q.top();
            q.pop();
        }
        return sum / (salary.size()-2);


    }
};