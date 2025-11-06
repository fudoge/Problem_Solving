type Heap []int

func (h Heap) Len() int           { return len(h) }
func (h Heap) Less(i, j int) bool { return h[i] < h[j] }
func (h Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Heap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *Heap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

func processQueries(c int, connections [][]int, queries [][]int) []int {
	alive := make([]bool, c+1)
	parent := make([]int, c+1)
	grids := make(map[int]*Heap)
	for i := 1; i <= c; i++ {
		parent[i] = i
		alive[i] = true
	}

	for _, con := range connections {
		a, b := con[0], con[1]
		merge(a, b, parent)
	}

	for i := 1; i <= c; i++ {
		root := getRoot(i, parent)
		if _, ok := grids[root]; !ok {
			grids[root] = &Heap{}
			heap.Init(grids[root])
		}
		heap.Push(grids[root], i)
	}

	ans := make([]int, 0, len(queries))
	for _, query := range queries {
		op := query[0]
		x := query[1]

		if op == 1 {
			if alive[x] {
				ans = append(ans, x)
			} else {
				root := getRoot(x, parent)
				for grids[root].Len() > 0 && alive[(*grids[root])[0]] == false {
					heap.Pop(grids[root])
				}
				if grids[root].Len() > 0 {
					ans = append(ans, (*grids[root])[0])
				} else {
					ans = append(ans, -1)
				}
			}
		} else {
			alive[x] = false
		}
	}

	return ans
}

func getRoot(x int, parent []int) int {
	if parent[x] == x {
		return x
	}
	parent[x] = getRoot(parent[x], parent)
	return parent[x]
}

func merge(x, y int, parent []int) {
	xRoot := getRoot(x, parent)
	yRoot := getRoot(y, parent)
	if xRoot == yRoot {
		return
	} else if xRoot < yRoot {
		parent[yRoot] = xRoot
	} else {
		parent[xRoot] = yRoot
	}
}
