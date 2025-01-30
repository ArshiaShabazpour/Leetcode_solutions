class Solution:
    def romanToInt(self, s: str) -> int:
        total = 0
        map = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        for i, c in enumerate(s):
            if i == len(s)-1:
                total += map[c]
                return total
            if map[s[i]] >= map[s[i+1]]:
                total += map[c]
            else:
                total -= map[c]
        return total

