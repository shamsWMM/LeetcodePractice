from os.path import commonprefix

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        return commonprefix(strs)