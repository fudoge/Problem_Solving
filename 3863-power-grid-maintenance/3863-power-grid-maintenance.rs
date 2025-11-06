use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};
impl Solution {
    pub fn process_queries(c: i32, connections: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let c = c as usize;
        let mut alive = vec![true; c + 1];
        let mut parent: Vec<usize> = (0..=c).collect();
        let mut grids: HashMap<usize, BinaryHeap<Reverse<usize>>> = HashMap::new();

        fn find(x: usize, parent: &mut Vec<usize>) -> usize {
            if parent[x] != x {
                parent[x] = find(parent[x], parent);
            }
            parent[x]
        }

        fn merge(x: usize, y: usize, parent: &mut Vec<usize>) {
            let x_root = find(x, parent);
            let y_root = find(y, parent);
            if x_root == y_root {
                return;
            } else if x_root < y_root {
                parent[y_root] = x_root;
            } else {
                parent[x_root] = y_root;
            }
        }

        for edge in connections {
            let (a, b) = (edge[0] as usize, edge[1] as usize);
            merge(a, b, &mut parent);
        }

        for i in 1..=c {
            let root = find(i, &mut parent);
            grids
                .entry(root)
                .or_insert_with(BinaryHeap::new)
                .push(Reverse(i));
        }

        let mut ans = Vec::with_capacity(queries.len());
        for query in queries {
            let (op, x) = (query[0], query[1] as usize);
            if op == 1 {
                if alive[x] {
                    ans.push(x as i32);
                } else {
                    let root = find(x, &mut parent);
                    if let Some(heap) = grids.get_mut(&root) {
                        while let Some(&Reverse(top)) = heap.peek() {
                            if alive[top] {
                                ans.push(top as i32);
                                break;
                            } else {
                                heap.pop();
                            }
                        }
                        if heap.is_empty() {
                            ans.push(-1);
                        }
                    } else {
                        ans.push(-1);
                    }
                }
            } else {
                alive[x] = false;
            }
        }
        ans
    }
}