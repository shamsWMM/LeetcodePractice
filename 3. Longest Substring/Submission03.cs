public class Solution
{ 
   public int LengthOfLongestSubstring(string s)
    {
        if (string.IsNullOrEmpty(s))
        {
            return 0;
        }

        var seen = new int[256];
        int leftIndex = 0, maxSize = 1, currentSize;

        for (int i = 0; i < s.Length; i++)
        {
            if (seen[s[i]] > leftIndex)
            {
                leftIndex = seen[s[i]];
            }

            seen[s[i]] = i + 1;
            currentSize = i - leftIndex + 1;
            maxSize = currentSize > maxSize ? currentSize : maxSize;
        }
        return maxSize;
    } 
}