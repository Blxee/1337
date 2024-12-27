class Solution:
    def longestPalindrome(self, s: str) -> str:
        for length in range(len(s), 0, -1):
            for position in range(len(s) - length + 1):
                substr = s[position:position + length]
                if self.is_palindrome(substr):
                    return substr
        return ""

    def is_palindrome(self, s: str) -> bool:
        return s == s[::-1]
