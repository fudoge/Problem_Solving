package main

import (
	"bufio"
	"fmt"
	"os"
)

type shark struct {
	id      int
	r       int
	c       int
	s       int
	d       int
	z       int
	isAlive bool
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var r, c, m int
	fmt.Fscan(reader, &r, &c, &m)

	arr := make([]*shark, m)
	for i := 0; i < m; i++ {
		var row, col, s, d, z int
		fmt.Fscan(reader, &row, &col, &s, &d, &z)

		if d == 1 || d == 2 {
			s %= 2 * (r - 1)
		} else {
			s %= 2 * (c - 1)
		}

		arr[i] = &shark{i, row - 1, col - 1, s, d, z, true}
	}

	ans := 0

	for i := 0; i < c; i++ {
		highestID := -1
		highestRow := r

		for _, sh := range arr {
			if !sh.isAlive || sh.c != i {
				continue
			}
			if highestRow > sh.r {
				highestRow = sh.r
				highestID = sh.id
			}
		}

		if highestID != -1 {
			arr[highestID].isAlive = false
			ans += arr[highestID].z
		}

		tempMat := make([][]int, r)
		for i := 0; i < r; i++ {
			tempMat[i] = make([]int, c)
			for j := 0; j < c; j++ {
				tempMat[i][j] = -1
			}
		}

		for _, sh := range arr {
			if !sh.isAlive {
				continue
			}

			dir := sh.d
			newRow, newCol := sh.r, sh.c

			if dir == 1 {
				toWall := sh.r
				toNextWall := toWall + r - 1
				if sh.s <= toWall {
					newRow = sh.r - sh.s
					if newRow == 0 {
						sh.d = 2
					}
				} else if sh.s <= toNextWall {
					newRow = sh.s - toWall
					if newRow != r-1 {
						sh.d = 2
					}
				} else {
					newRow = r - 1 - (sh.s - toNextWall)
				}
			} else if dir == 2 {
				toWall := r - 1 - sh.r
				toNextWall := toWall + r - 1
				if sh.s <= toWall {
					newRow = sh.r + sh.s
					if newRow == r-1 {
						sh.d = 1
					}
				} else if sh.s <= toNextWall {
					newRow = toNextWall - sh.s
					if newRow != 0 {
						sh.d = 1
					}
				} else {
					newRow = sh.s - toNextWall
				}
			} else if dir == 3 {
				toWall := c - 1 - sh.c
				toNextWall := toWall + c - 1
				if sh.s <= toWall {
					newCol = sh.c + sh.s
					if newCol == c-1 {
						sh.d = 4
					}
				} else if sh.s <= toNextWall {
					newCol = toNextWall - sh.s
					if newCol != 0 {
						sh.d = 4
					}
				} else {
					newCol = sh.s - toNextWall
				}
			} else {
				toWall := sh.c
				toNextWall := toWall + c - 1
				if sh.s <= toWall {
					newCol = sh.c - sh.s
					if newCol == 0 {
						sh.d = 3
					}
				} else if sh.s <= toNextWall {
					newCol = sh.s - toWall
					if newCol != c-1 {
						sh.d = 3
					}
				} else {
					newCol = c - 1 - (sh.s - toNextWall)
				}
			}

			if tempMat[newRow][newCol] == -1 {
				tempMat[newRow][newCol] = sh.id
			} else {
				if arr[tempMat[newRow][newCol]].z < sh.z {
					arr[tempMat[newRow][newCol]].isAlive = false
					tempMat[newRow][newCol] = sh.id
				} else {
					sh.isAlive = false
				}
			}
		}

		for row := 0; row < r; row++ {
			for col := 0; col < c; col++ {
				if tempMat[row][col] != -1 {
					arr[tempMat[row][col]].r = row
					arr[tempMat[row][col]].c = col
				}
			}
		}
	}

	fmt.Fprintln(writer, ans)
}