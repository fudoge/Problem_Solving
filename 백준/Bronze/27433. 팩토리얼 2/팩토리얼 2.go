package main

import "fmt"

func fact(x int) int {
    if x <= 1 {
        return 1
    }
    return fact(x-1) * x
}

func main() {
    var n int
    fmt.Scanf("%d", &n)
    
    fmt.Println(fact(n))
}