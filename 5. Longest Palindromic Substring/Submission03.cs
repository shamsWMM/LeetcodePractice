public class Solution
{
    // Fastest submission
    public string LongestPalindrome(string s)
    {
        int len;
        if (string.IsNullOrEmpty(s) || (len = s.Length) < 2)
            return s;

        int max = 1, index = 0, left, right;
        for (int i = 0; i < len && len - i > max / 2; i++)
        {
            left = i; right = i;
            while (left >= 0 && right < len && s[left] == s[right])
            {
                if (right++ - left-- + 1 > max)
                {
                    max = right - left -1;
                    index = left + 1;
                }
            }

            left = i; right = i + 1;
            while (left >= 0 && right < len && s[left] == s[right])
            {
                if (right++ - left-- + 1 > max)
                {
                    max = right - left -1;
                    index = left + 1;
                }
            }
        }
        return s.Substring(index, max);
    }
}