import Foundation

func solution(_ A: [Int], _ B: [Int]) -> Int {
    var ans = 0

    var pseudoA = A
    var pseudoB = B
    
    pseudoA.sort()
    pseudoB.sort(by: >)
    
    for i in 0..<A.count {
        ans += pseudoA[i] * pseudoB[i]
    }

    return ans
}
