func countTriples(n int) int {
    ans := 0
    for i := 1; i <= n; i++ {
        for j := i+1; j <= n; j++ {
            root := int(math.Sqrt(float64(i*i+j*j)))
            if root <= n && root * root == i * i + j * j {
                ans += 2
            }
        }
    } 
    return ans
}