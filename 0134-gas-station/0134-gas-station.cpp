class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int sum = 0;
        int location = 0;
        for(int i = 0; i < n; i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                location = i + 1;
                sum += tank;
                tank = 0;
                }
            }
        sum += tank;
        if(sum < 0){
            return -1;
        }    
        else{
            return location;
        }
    }
};