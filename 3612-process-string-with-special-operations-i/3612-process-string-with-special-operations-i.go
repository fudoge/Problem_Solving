func processStr(s string) string {
    result := make([]byte, 0)
    for _, ch := range s {
        if ch >= 'a' && ch <= 'z' {
            result = append(result, byte(ch))
        } else if ch == '*' {
            if len(result) == 0 { continue }
            result = result[0:len(result)-1]
        } else if ch == '#' {
            result = append(result, result...)
        } else if ch == '%' {
            n := len(result)
            for i := 0; i < n/2; i++ {
                result[i], result[n-i-1] = result[n-i-1], result[i]
            }
        }
    }    

    return string(result)
}