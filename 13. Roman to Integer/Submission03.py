class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        sum = 0
        sum += s.count('M') * 1000 
        sum += s.count('D') * 500
        sum += s.count('C') * 100
        sum += s.count('L') * 50
        sum += s.count('X') * 10
        sum += s.count('V') * 5
        sum += s.count('I') * 1
        sum -= s.count('CM') * 200
        sum -= s.count('CD') * 200
        sum -= s.count('XC') * 20
        sum -= s.count('XL') * 20
        sum -= s.count('IX') * 2
        sum -= s.count('IV') * 2

        return sum