func angleClock(hour int, minutes int) float64 {
    hDeg := 30.0 * float64(hour) + 0.5 * float64(minutes)
    mDeg := 6.0 * float64(minutes)
    if hDeg >= 360.0 {
        hDeg -= 360.0
    }

    lo := min(hDeg, mDeg)
    hi := max(hDeg, mDeg)

    return min(hi - lo, 360.0 - hi + lo)
}