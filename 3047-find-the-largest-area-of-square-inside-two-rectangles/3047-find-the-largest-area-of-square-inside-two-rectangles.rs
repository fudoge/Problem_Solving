impl Solution {
    pub fn largest_square_area(bottom_left: Vec<Vec<i32>>, top_right: Vec<Vec<i32>>) -> i64 {
        let mut ans = 0i64;
        let n = bottom_left.len();

        for i in 0..n {
            for j in i+1..n {
                let bl_x = bottom_left[i][0].max(bottom_left[j][0]);
                let bl_y = bottom_left[i][1].max(bottom_left[j][1]);
                let tr_x = top_right[i][0].min(top_right[j][0]);
                let tr_y = top_right[i][1].min(top_right[j][1]);

                if bl_x < tr_x && bl_y < tr_y {
                    let side = (tr_x - bl_x).min(tr_y - bl_y) as i64;
                    ans = ans.max(side * side);
                }
            }
        }

        ans        
    }
}