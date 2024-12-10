class Solution:
    def balancedString(self, s: str) -> int:
        dict = {}

        for c in s:
            if c in dict:
                dict[c] += 1
            else:
                dict[c] = 1

        l = 0
        lst = []

        for c in s:
            if c 


        return l
