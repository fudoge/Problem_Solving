type Edge struct {
	node int
	prob float64
}

type MaxHeap []Edge

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i].prob > h[j].prob }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(Edge))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func maxProbability(n int, edges [][]int, succProb []float64, start_node int, end_node int) float64 {
	graph := make([][]Edge, n)
	for i := 0; i < len(edges); i++ {
		a := edges[i][0]
		b := edges[i][1]
		prob := succProb[i]
		graph[a] = append(graph[a], Edge{node: b, prob: prob})
		graph[b] = append(graph[b], Edge{node: a, prob: prob})
	}

	prob := make([]float64, n)
	prob[start_node] = 1.0

	maxHeap := &MaxHeap{}
	heap.Init(maxHeap)
	heap.Push(maxHeap, Edge{node: start_node, prob: 1.0})

	for maxHeap.Len() > 0 {
		curr := heap.Pop(maxHeap).(Edge)
		currNode := curr.node
		currProb := curr.prob

		if currNode == end_node {
			return currProb
		}

		for _, next := range graph[currNode] {
			nextNode := next.node
			nextProb := currProb * next.prob

			if nextProb > prob[nextNode] {
				prob[nextNode] = nextProb
				heap.Push(maxHeap, Edge{node: nextNode, prob: nextProb})
			}
		}
	}

	return 0.0
}
