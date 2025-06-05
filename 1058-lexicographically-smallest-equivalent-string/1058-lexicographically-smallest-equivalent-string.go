type DisjointSet []int

func NewDisjointSet(n int) DisjointSet {
	d := make(DisjointSet, n)
	for i := 0; i < n; i++ {
		d[i] = i
	}
	return d
}

func (d *DisjointSet) getRoot(x int) int {
	if (*d)[x] == x {
		return x
	}
	(*d)[x] = d.getRoot((*d)[x]) 
	return (*d)[x]
}

func (d *DisjointSet) union(x, y int) {
	rootX := d.getRoot(x)
	rootY := d.getRoot(y)

	if rootX == rootY {
		return
	}

	if rootX < rootY {
		(*d)[rootY] = rootX
	} else {
		(*d)[rootX] = rootY
	}
}

func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
	d := NewDisjointSet(26)

	for i := 0; i < len(s1); i++ {
		d.union(int(s1[i]-'a'), int(s2[i]-'a'))
	}

	var sb strings.Builder

	for _, ch := range baseStr {
		root := d.getRoot(int(ch - 'a'))
		sb.WriteByte(byte(root) + 'a')
	}

	return sb.String()
}