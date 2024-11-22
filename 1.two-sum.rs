use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut result = Vec::new();
        let mut map = HashMap::new();

        for (i, val) in nums.iter().enumerate() {
            map.insert(val, i);
        }

        for (i, val_a) in nums.iter().enumerate() {
            if let Some(&j) = map.get(&(target - val_a)) {
                if (i != j) {
                    result.push(i as i32);
                    result.push(j as i32);
                    break;
                }
            }
        }

        return result;
    }
}
