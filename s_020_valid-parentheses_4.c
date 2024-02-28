/*
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
**Example 1:**
**Input:** s = "()"
**Output:** true
**Example 2:**
**Input:** s = "()[]{}"
**Output:** true
**Example 3:**
**Input:** s = "(]"
**Output:** false
**Constraints:**
* `1 <= s.length <= 104`
* `s` consists of parentheses only `'()[]{}'`.
*/

bool isValid(char* s) {
    int i = 0;
    int circle = 0, square = 0, curly = 0;

    while (s[i] != '\0') {
        switch (s[i]) {
            case '(':
                circle++;
                break;
            case ')':
                circle--;
                break;
            case '[':
                square++;
                break;
            case ']':
                square--;
                break;
            case '{':
                curly++;
                break;
            case '}':
                curly--;
                break;
        }
        if (circle < 0 || square < 0 || curly < 0)
            return 0;
        i++;
    }

    return circle | square | curly == 0;
}
