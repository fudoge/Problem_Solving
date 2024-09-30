#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class CustomStack {
private:
    vector<int> arr;
    vector<int> inc;
    int top;
    int maxSize;
public:
    CustomStack(int maxSize) {
        top = -1;
        this -> maxSize = maxSize;
        arr.resize(maxSize);
        inc.resize(maxSize, 0);
    }
    
    void push(int x) {
        if(top == maxSize-1) return;
        top++;
        arr[top] = x;
    }
    
    int pop() {
        if(top < 0) return -1;
        int popped = arr[top] + inc[top];

        if(top > 0) {
            inc[top-1] += inc[top];
        }
        inc[top] = 0;
        top--;
        return popped;
    }
    
    void increment(int k, int val) {
        if(top >= 0) {
            int limit = min(k-1, top);
            inc[limit] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */