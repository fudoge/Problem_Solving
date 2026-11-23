type ProductOfNumbers struct {
    nums []int
}


func Constructor() ProductOfNumbers {
    return ProductOfNumbers{
        nums: make([]int, 0),
    }
}


func (this *ProductOfNumbers) Add(num int)  {
    n := len(this.nums) 
    if num == 0 { 
        this.nums = this.nums[:0] 
    } else if len(this.nums) == 0 {
        this.nums = append(this.nums, num) 
    } else { 
        this.nums = append(this.nums, this.nums[n-1] * num)
    }
}


func (this *ProductOfNumbers) GetProduct(k int) int {
    n := len(this.nums) 
    if k > n { 
        return 0 
    } else if k == n { 
        return this.nums[n-1] 
    } else {
        return this.nums[n-1] / this.nums[n-k-1]
    }
}


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */