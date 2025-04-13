from typing import List

keyboard = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
}


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result: List[str] = []

        def traverse(i: int, path: List[str]):
            nonlocal digits, result

            if i == len(digits):
                result.append("".join(path))
                return

            chars = keyboard[digits[i]]

            for ch in chars:
                path.append(ch)
                traverse(i + 1, path)
                path.pop()

        traverse(0, [])

        return result