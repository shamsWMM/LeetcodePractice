class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        incs = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbs = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        result = ""

        for i, inc in enumerate(incs):
            result += symbs[i] * (num // inc)
            num = num % inc     
             
        return result
    
solution = Solution()
print(solution.intToRoman(3749))  # Output: "MCMXCIV"
