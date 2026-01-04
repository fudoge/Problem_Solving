func sumFourDivisors(nums []int) int {
    ans := 0    
    for _, num := range nums {
        root := int(math.Sqrt(float64(num)));
        sum := num + 1
        cnt := 0
        for i := 2; i <= root; i++ {
            if num % i == 0 {
                if i*i == num { 
                    cnt++
                    sum += i
                } else { 
                    cnt += 2
                    sum += i + num / i
                }
            }
        }
        if cnt == 2 {
            ans += sum
        }
    }

    return ans
}