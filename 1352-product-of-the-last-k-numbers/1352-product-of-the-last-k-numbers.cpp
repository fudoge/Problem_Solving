#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class ProductOfNumbers {
    vector<int> nums;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        int n = nums.size();
        if(num == 0) nums.clear();
        else if(nums.empty()) nums.push_back(num);
        else nums.push_back(nums[n-1] * num);
    }
    
    int getProduct(int k) {
        int n = nums.size();
        if(k > n) return 0;
        if(k == n) return nums[n-1];
        return nums[n-1] / nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */