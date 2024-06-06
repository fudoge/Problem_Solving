class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;

        for(const auto student : students) {
            q.push(student);
        }

        for(int i = sandwiches.size()-1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }

        while(!q.empty()) {
            bool taken = false;
            for(int i = 0; i < q.size(); i++) {
                if(q.front() == st.top()) {
                    st.pop();
                    taken = true;
                } else {
                    q.push(q.front());
                }
                q.pop();

                
            }
            if(!taken) break;
        }

        return q.size();
    }
};