class KthLargest {
private:
    int k;
    vector<int> arr;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        sort(nums.begin(), nums.end(), greater<int>());
        for(const auto &num : nums) arr.push_back(num);
    }
    
    int add(int val) {
        for(int i = 0; i < arr.size(); i++) {
            if(val > arr[i]) {
                arr.insert(arr.begin() + i, val);
                return arr[k-1];
            }
        }
        arr.push_back(val);
        return arr[k-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */