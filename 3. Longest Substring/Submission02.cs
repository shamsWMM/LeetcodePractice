public class Solution
{
   public int LengthOfLongestSubstring(string s)
    {
        if (string.IsNullOrEmpty(s))
        {
            return 0;
        }

        var seen = new HashSet<char>(256);
        int leftIndex = 0, maxSize = 1, currentSize;

        for (int i = 0; i < s.Length; i++)
        {
            if (seen.Contains(s[i]))
            {
                int j;
                for (j = leftIndex; s[j] != s[i]; j++)
                {
                    seen.Remove(s[j]);
                }

                leftIndex = j + 1;
            }

            seen.Add(s[i]);
            currentSize = i - leftIndex + 1;
            maxSize = currentSize > maxSize ? currentSize : maxSize;
        }
        return maxSize;
    }
}