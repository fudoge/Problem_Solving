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
    int top;
    int maxSize;
public:
    CustomStack(int maxSize) {
        top = -1;
        this -> maxSize = maxSize;
        arr.resize(maxSize);
    }
    
    void push(int x) {
        if(top == maxSize-1) return;
        top++;
        arr[top] = x;
    }
    
    int pop() {
        if(top < 0) return -1;
        int popped = arr[top];
        top--;
        return popped;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i <= top; ++i) {
            arr[i] += val;
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