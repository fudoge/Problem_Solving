func maximumValueSum(nums []int, k int, edges [][]int) int64 {
    sum := int64(0)
    positiveMin := 1000000000
    negativeMax := -1000000000
    cnt := 0
    
    for _, num := range nums {
        flipped := num ^ k 
        profit := flipped - num
        sum += int64(num)
        if profit > 0 {
            sum += int64(profit)
            positiveMin = min(positiveMin, profit)
            cnt++
        } else {
            negativeMax = max(negativeMax, profit)
        }
    } 

    if cnt % 2 == 0 {
        return sum
    }
    return max(sum + int64(negativeMax), sum - int64(positiveMin))
}