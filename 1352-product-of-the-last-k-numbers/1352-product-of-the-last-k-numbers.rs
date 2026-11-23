struct ProductOfNumbers {
    nums: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ProductOfNumbers {

    fn new() -> Self {
        Self {
            nums: Vec::new(),
        }
    }
    
    fn add(&mut self, num: i32) {
        let n = self.nums.len();
        if num == 0 { self.nums.clear(); }
        else if self.nums.is_empty() { self.nums.push(num); }
        else { self.nums.push(self.nums[n-1] * num); }
    }
    
    fn get_product(&mut self, k: i32) -> i32 {
        let n = self.nums.len();
        let k = k as usize;
        if k > n { 0 }
        else if k == n { self.nums[n-1] }
        else { self.nums[n-1] / self.nums[n-k-1] }
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers::new();
 * obj.add(num);
 * let ret_2: i32 = obj.get_product(k);
 */