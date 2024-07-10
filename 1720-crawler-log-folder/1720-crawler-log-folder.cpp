class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(const auto &operation : logs) {
            if(operation == "./") {
                continue;
            } else if(operation == "../") {
                if(depth == 0) continue;
                depth--;
            } else {
                depth++;
            }
        }

        return depth;
    }
};