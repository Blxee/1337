class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        total_nums = sorted(nums1 + nums2)
        total_len = len(total_nums)

        if total_len % 2 == 1:
            return total_nums[total_len // 2]
        else:
            return (total_nums[total_len // 2 - 1] + total_nums[total_len // 2]) / 2
