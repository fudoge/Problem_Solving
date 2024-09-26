class MyCalendar {
private:
    vector<pair<int, int>> table;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n = table.size();
        end--;

        if(n == 0) {
            table.push_back({start, end});
            return true;
        }

        if(end < table[0].first) {
            table.insert(table.begin(), {start, end});
            return true;
        }
        for(int i = 0; i < n-1; ++i) {
            if(start > table[i].second && end < table[i+1].first) {
                table.insert(table.begin()+i+1, {start, end});
                return true;
            }
        }
        if(start > table[n-1].second) {
            table.push_back({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */