class AllOne {
private:
    unordered_map<string, int> count; 
    set<pair<int, string>> sets;
public:
    AllOne() {
        count.clear();
    }
    
    void inc(string key) {
        int n = count[key];
        count[key]++;
        sets.erase({n, key});
        sets.insert({n+1, key});
    }
    
    void dec(string key) {
       int n = count[key];
        count[key]--;
        sets.erase({n, key});
        if(n-1 > 0) sets.insert({n-1, key});
        else count.erase(key);
    }
    
    string getMaxKey() {
        if(!sets.empty()) return sets.rbegin() -> second;
        return "";
    }
    
    string getMinKey() {
        if(!sets.empty()) return sets.begin() -> second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */