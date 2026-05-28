type TrieNode struct {
    key      int
    length   int
    children []*TrieNode
}

type Trie struct {
    root *TrieNode
}

func newTrieNode() *TrieNode {
    return &TrieNode{
        key:      -1,
        length:   1 << 30,
        children: make([]*TrieNode, 26),
    }
}

func (node *TrieNode) update(idx int, length int) {
    if node.key == -1 || length < node.length || (length == node.length && idx < node.key) {
        node.key = idx
        node.length = length
    }
}

func (t *Trie) insert(s string, idx int, originalLength int) {
    p := t.root

    p.update(idx, originalLength)

    for i := 0; i < len(s); i++ {
        ord := int(s[i] - 'a')

        if p.children[ord] == nil {
            p.children[ord] = newTrieNode()
        }

        p = p.children[ord]
        p.update(idx, originalLength)
    }
}

func (t *Trie) search(s string) int {
    p := t.root

    for i := 0; i < len(s); i++ {
        ord := int(s[i] - 'a')

        if p.children[ord] == nil {
            return p.key
        }

        p = p.children[ord]
    }

    return p.key
}

func stringIndices(wordsContainer []string, wordsQuery []string) []int {
    t := &Trie{
        root: newTrieNode(),
    }

    for i, word := range wordsContainer {
        t.insert(reverse(word), i, len(word))
    }

    ans := make([]int, len(wordsQuery))

    for i, query := range wordsQuery {
        ans[i] = t.search(reverse(query))
    }

    return ans
}

func reverse(s string) string {
    r := []rune(s)

    for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }

    return string(r)
}