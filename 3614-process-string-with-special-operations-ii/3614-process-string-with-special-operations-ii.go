func processStr(s string, k int64) byte {
    length := int64(0)    
    for _, ch := range s {
        if ch == '*' {
            if length > 0 {
                length--
            }
        } else if ch == '#' {
            length <<= 1
        } else if ch == '%' {
            continue
        } else {
            length++
        }
    }

    if k+1 > length {
        return '.'
    }
    for i := len(s)-1; i>= 0; i-- {
        ch := s[i]
        if ch == '*' {
            length++
        } else if ch == '#' {
            if k+1 > (length+1)/2 {
                k -= length/2
            }
            length = (length+1)/2
        } else if ch == '%' {
            k = length - k - 1
        } else {
            if k + 1 == length {
                return ch
            }
            length--
        }
    }

    return '.'
}