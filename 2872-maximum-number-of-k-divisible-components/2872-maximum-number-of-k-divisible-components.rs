impl Solution {
    pub fn max_k_divisible_components(
        n: i32,
        edges: Vec<Vec<i32>>,
        values: Vec<i32>,
        k: i32,
    ) -> i32 {
        let n = n as usize;
        let mut adj = vec![vec![]; n];
        let mut ans = 0;
        for edge in edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            adj[u].push(v);
            adj[v].push(u);
        }

        fn dfs(
            curr: usize,
            parent: usize,
            values: &Vec<i32>,
            adj: &Vec<Vec<usize>>,
            k: i64,
            ans: &mut i32,
        ) -> i64 {
            let mut current_sum = values[curr] as i64;

            for &neighbor in &adj[curr] {
                if neighbor != parent {
                    current_sum += dfs(neighbor, curr, values, adj, k, ans);
                }
            }

            if current_sum % k == 0 {
                *ans += 1;
                return 0;
            }

            current_sum
        }

        dfs(0, usize::MAX, &values, &adj, k as i64, &mut ans);

        ans
    }
}