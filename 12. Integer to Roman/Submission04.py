# Slower solution but looks like python3 dicts preserve order of items
class Solution:
    def intToRoman(self, num: int) -> str:
        numDict = {
            1000: "M",
            900: "CM",
            500: "D",
            400: "CD",
            100: "C",
            90: "XC",
            50: "L",
            40: "XL",
            10: "X",
            9: "IX",
            5: "V",
            4: "IV",
            1: "I"
        }

        result = ""

        for key, value in numDict.items():
            result += value * (num // key)
            num = num % key     
             
        return result
    
solution = Solution()
print(solution.intToRoman(3749))
