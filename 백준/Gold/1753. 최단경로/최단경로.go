package main

import (
	"bufio"
	"container/heap"
	"fmt"
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

	var v, e, k int32
	fmt.Fscan(reader, &v, &e, &k)

	adj := make([][]Pair, v+1)
	for i := int32(0); i <= v; i++ {
		adj[i] = make([]Pair, 0)
	}
	for i := int32(0); i < e; i++ {
		var u, v, w int32
		fmt.Fscan(reader, &u, &v, &w)
		adj[u] = append(adj[u], Pair{v, w})
	}
	dist := make([]int32, v+1)
	for i := int32(1); i <= v; i++ {
		dist[i] = int32(1e9)
	}

	pq := &MinHeap{}
	heap.Init(pq)
	heap.Push(pq, Pair{k, 0})
	dist[k] = 0

	for pq.Len() > 0 {
		x := heap.Pop(pq).(Pair)
		curr := x.First
		cost := x.Second

		if dist[curr] < cost {
			continue
		}

		for _, next := range adj[curr] {
			if dist[next.First] > dist[curr]+next.Second {
				dist[next.First] = dist[curr] + next.Second
				heap.Push(pq, Pair{next.First, dist[next.First]})
			}
		}
	}

	for i := int32(1); i <= v; i++ {
		if dist[i] == int32(1e9) {
			fmt.Fprintln(writer, "INF")
		} else {
			fmt.Fprintln(writer, dist[i])
		}
	}
}