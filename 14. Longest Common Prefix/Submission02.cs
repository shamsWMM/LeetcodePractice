public class Solution
{
    public string LongestCommonPrefix(string[] strs)
    {
        int strsLen = strs.Length;
        if (strsLen == 0)
            return "";
        if (strsLen == 1)
            return strs[0];

        string s = strs[0];
        int sLen = s.Length;

        for (int i = 0; i < sLen; i++)
        {
            for (int j = 1; j < strsLen; j++)
            {
                int sjLen = strs[j].Length;
                if (i >= sjLen || strs[j][i] != s[i])
                {
                    return s.Substring(0, i);
                }
            }
        }
        return s;
    }
}
