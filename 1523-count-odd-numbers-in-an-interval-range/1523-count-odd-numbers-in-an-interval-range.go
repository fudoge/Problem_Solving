func countOdds(low int, high int) int {
    bonus := 0
    if low % 2 == 1 || high % 2 == 1 {
        bonus++
    }
    return (high - low) / 2 + bonus
}