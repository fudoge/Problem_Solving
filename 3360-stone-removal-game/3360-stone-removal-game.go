func canAliceWin(n int) bool {
    alice := 10
    bob := 9
    aliceTurn := true
    for n > 0 {
        if aliceTurn {
            if n - alice < 0 {
                return false
            }
            n -= alice
            alice -= 2
            aliceTurn = !aliceTurn
        } else {
            if n - bob < 0 {
                return true
            }
            n -= bob
            bob -= 2
            aliceTurn = !aliceTurn
        }
    }    

    return !aliceTurn
}