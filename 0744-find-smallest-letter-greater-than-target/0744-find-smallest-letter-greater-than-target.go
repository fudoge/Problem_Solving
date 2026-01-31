func nextGreatestLetter(letters []byte, target byte) byte {
    idx := sort.Search(len(letters), func(i int) bool {
        return byte(letters[i]) > target
    })
    if idx == len(letters) {
        return letters[0]
    }
    return letters[idx]
}