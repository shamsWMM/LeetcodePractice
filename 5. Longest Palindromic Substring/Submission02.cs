public class Solution
{
    public string LongestPalindrome(string s)
    {
        int len;
        if (string.IsNullOrEmpty(s) || (len = s.Length) < 2)
            return s;

        ReadOnlySpan<char> span = s.AsSpan();
        ReadOnlySpan<char> max = span.Slice(0, 1);
        for (int i = 0; i < len && len - i > max.Length / 2; i++)
        {
            CheckPalindrome(i, in span, len, ref max);
        }
        return max.ToString();
    }

    void CheckPalindrome(int i, in ReadOnlySpan<char> span, int len, ref ReadOnlySpan<char> max)
    {
        int left = i, right = i;
        while (left >= 0 && right < len && span[left] == span[right])
        {
            if (right - left + 1 > max.Length)
            {
                max = span.Slice(left, right - left + 1);
            }
            left--;
            right++;
        }

        left = i; right = i + 1;
        while (left >= 0 && right < len && span[left] == span[right])
        {
            if (right - left + 1 > max.Length)
            {
                max = span.Slice(left, right - left + 1);
            }
            left--;
            right++;
        }
    }
}