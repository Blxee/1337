impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut max = 0;

        let (mut i, mut j) = (0, height.len() - 1);
        while i < j {
            let (h1, h2) = (height[i], height[j]);
            let width = i.abs_diff(j) as i32;
            let height = h1.min(h2);
            let amount = width * height;

            if amount > max {
                // dbg!(i, j, h1, h2, width, height);
                max = amount;
            }

            if h1 < h2 {
                i += 1;
            } else {
                j -= 1;
            }
        }

        max
    }
}
