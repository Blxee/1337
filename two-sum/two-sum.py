class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        map = {nums[i]: i for i in range(len(nums))}
        for i in range(len(nums)):
            j = map.get(target - nums[i])
            if j and i != j:
                return [i, j]
        return []
