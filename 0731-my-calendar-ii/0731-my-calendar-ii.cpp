class MyCalendarTwo {
    map<int, int> timeline;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        timeline[start] += 1;
        timeline[end] -= 1;
        
        int ongoing = 0;
        for(auto &[time, delta] : timeline){
            ongoing += delta;
            if(ongoing >= 3){
                timeline[start] -= 1;
                timeline[end] += 1;
                return false;
            }
        }
        return true;
    }
};