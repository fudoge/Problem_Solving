package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader
var writer *bufio.Writer

var dx []int32 = []int32{-1, 1, 0, 0}
var dy []int32 = []int32{0, 0, -1, 1}

type Pair struct {
	First  int32
	Second int32
}

type Queue struct {
	data []Pair
}

func (q *Queue) Empty() bool {
	return len(q.data) == 0
}

func (q *Queue) Push(p Pair) {
	q.data = append(q.data, p)
}

func (q *Queue) Pop() (Pair, bool) {
	if q.Empty() {
		return Pair{}, false
	}
	front := q.data[0]
	q.data = q.data[1:]
	return front, true
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, k int32
	fmt.Fscan(reader, &n, &m, &k)

	mat := make([][]bool, n)

	for i := int32(0); i < n; i++ {
		mat[i] = make([]bool, m)
	}

	var lbx, lby, rtx, rty int32
	for l := int32(0); l < k; l++ {
		fmt.Fscan(reader, &lbx, &lby, &rtx, &rty)

		for i := lby; i < rty; i++ {
			for j := lbx; j < rtx; j++ {
				mat[i][j] = true
			}
		}
	}

	ans := make([]int32, 0)

	for i := int32(0); i < n; i++ {
		for j := int32(0); j < m; j++ {
			if !mat[i][j] {
				size := int32(1)
				q := Queue{}
				q.Push(Pair{i, j})
				mat[i][j] = true

				for !q.Empty() {
					curr, _ := q.Pop()
					x := curr.First
					y := curr.Second

					for k := 0; k < 4; k++ {
						nx := x + dx[k]
						ny := y + dy[k]

						if nx < 0 || ny < 0 || nx >= n || ny >= m || mat[nx][ny] {
							continue
						}
						mat[nx][ny] = true
						size++
						q.Push(Pair{nx, ny})
					}
				}

				ans = append(ans, size)
			}
		}
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	fmt.Fprintln(writer, len(ans))
	for _, v := range ans {
		fmt.Fprintf(writer, "%d ", v)
	}
	fmt.Fprintln(writer)
}