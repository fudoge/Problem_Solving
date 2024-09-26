class MyCalendar {
private:
    vector<pair<int, int>> table;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n = table.size();
        
        int left = 0;
        int right = n;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (table[mid].second <= start) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if ((left == 0 || table[left-1].second <= start) && (left == n || end <= table[left].first)) {
            table.insert(table.begin() + left, {start, end});
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