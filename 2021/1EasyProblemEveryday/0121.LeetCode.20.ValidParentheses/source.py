_BRACKETS_PAIRS_ = {"(": ")", "{": "}", "[": "]"}


class Solution:
    def isValid(self, s: str) -> bool:
        brackets = []
        for ch in s:
            close_bracket = _BRACKETS_PAIRS_.get(ch, None)            
            if close_bracket is not None:  # open bracket
                brackets.append(close_bracket)            
            elif len(brackets) == 0 or ch != brackets[-1]:                
                return False
            else:
                brackets.pop()
        return len(brackets) == 0


if __name__ == "__main__":
    print(Solution().isValid("()"))
    print(Solution().isValid("{}"))
    print(Solution().isValid("[]"))