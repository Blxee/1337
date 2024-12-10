class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=self.sort_key)

    def sort_key(self, x):
        return bin(x).count('1') + x / 10e9
