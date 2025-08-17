impl Solution {
    pub fn count_valid_selections(nums: Vec<i32>) -> i32 {
        let mut total: i32 = 0;
        for i in 0..nums.len() {
            if nums[i] == 0 {
                let lsum = nums[..i].iter().sum::<i32>();
                let rsum = nums[i..].iter().sum::<i32>();
                let diff = (lsum - rsum).abs();
                if diff == 1 {
                    total += 1;
                } else if diff == 0 {
                    total += 2;
                }
            }
        }
        total
    }
}
