package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
)

type Pair struct {
	First  int32
	Second int32
}

type MinHeap []Pair

func (h MinHeap) Len() int { return len(h) }
func (h MinHeap) Less(i, j int) bool {
	if h[i].Second == h[j].Second {
		return h[i].First < h[j].First
	}
	return h[i].Second < h[j].Second
}
func (h MinHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}
func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Pair))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, src, dst, m int32

	fmt.Fscan(reader, &n, &src, &dst, &m)
	adj := make([][]int32, n+1)
	for i := int32(0); i <= n; i++ {
		adj[i] = make([]int32, 0)
	}

	for i := int32(0); i < m; i++ {
		var u, v int32
		fmt.Fscan(reader, &u, &v)
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	dist := make([]int32, n+1)
	for i := int32(1); i <= n; i++ {
		dist[i] = math.MaxInt32
	}

	pq := &MinHeap{}
	heap.Init(pq)
	dist[src] = 0
	heap.Push(pq, Pair{src, 0})

	for pq.Len() > 0 {
		x := heap.Pop(pq).(Pair)
		curr := x.First
		cost := x.Second

		if dist[curr] < cost {
			continue
		}

		for _, next := range adj[curr] {
			if dist[next] > dist[curr]+1 {
				dist[next] = dist[curr] + 1
				heap.Push(pq, Pair{next, dist[next]})
			}
		}
	}

	if dist[dst] == math.MaxInt32 {
		fmt.Fprintln(writer, -1)
	} else {
		fmt.Fprintln(writer, dist[dst])
	}
}