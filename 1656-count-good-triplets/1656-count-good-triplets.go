func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
func countGoodTriplets(arr []int, a int, b int, c int) int {
    ans := 0
    for i := 0; i < len(arr)-2; i++ {
        for j := i+1; j < len(arr)-1; j++ {
            if abs(arr[i]-arr[j]) > a {
                continue
            }
            for k := j+1; k < len(arr); k++ {
                if abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c {
                    ans++
                }                
            }
        }
    }
    return ans
}