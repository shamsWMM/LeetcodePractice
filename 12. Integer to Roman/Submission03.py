class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        numerals = [
        (1000, "M"),
        (900, "CM"),
        (500, "D"),
        (400, "CD"),
        (100, "C"),
        (90, "XC"),
        (50, "L"),
        (40, "XL"),
        (10, "X"),
        (9, "IX"),
        (5, "V"),
        (4, "IV"),
        (1, "I"),
        ]
        result = ""

        for numeral in numerals:
            result += numeral[1] * (num // numeral[0])
            num = num % numeral[0]     
             
        return result
    
solution = Solution()
print(solution.intToRoman(3749))  # Output: "MCMXCIV"
