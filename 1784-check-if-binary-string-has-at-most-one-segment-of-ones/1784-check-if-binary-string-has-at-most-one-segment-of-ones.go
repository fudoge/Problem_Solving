func checkOnesSegment(s string) bool {
    seg := 0
    last := 0
    for _, ch := range s {
        c := int(byte(ch) - '0')
        if c == 1{
            if last == 0 {
                seg++
            }
        }
        last = c
    }

    return seg <= 1
}