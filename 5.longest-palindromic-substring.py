class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 1 or (len(s) == 2 and s[0] == s[1]):
            return s
        longest = ''
        maxlen = 0
        for i in range(len(s)):
            for j in reversed(range(i + 1)):
                if i + j > len(s):
                    continue
                substr = s[i - j:i + j + 1]
                if self.is_palindrome(substr) and len(substr) > maxlen:
                    longest = substr
                    maxlen = len(substr)
                    break
                substr = s[i - j:i + j]
                if self.is_palindrome(substr) and len(substr) > maxlen:
                    longest = substr
                    maxlen = len(substr)
                    break
        return longest

    def is_palindrome(self, s: str):
        if len(s) % 2 == 1:
            s = s[:len(s) // 2] + s[len(s) // 2 + 1:]
        return s[:len(s) // 2] == s[len(s) // 2:][::-1]
