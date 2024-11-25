class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        total = 0

        for word in words:
            chars_tmp = chars
            is_good = True
            for c in word:
                if c not in chars_tmp:
                    is_good = False
                    break
                else:
                    chars_tmp = chars_tmp.replace(c, '', 1)
            if is_good:
                total += len(word)

        return total
        
