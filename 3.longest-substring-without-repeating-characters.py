class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        chr_lst = []
        for c in s:
            while c in chr_lst:
                chr_lst.pop(0)
            chr_lst.append(c)
            if len(chr_lst) > max_len:
                max_len = len(chr_lst)
        return max_len
            

        
