public class Solution
{
    public string Convert(string s, int numRows)
    {
        var len = s.Length;
        if (numRows <= 1 || len <= 1)
        {
            return s;
        }

        var maxStep = 2 * (numRows - 1);
        var sb = new StringBuilder(len);

        for (int row = 0; row < numRows; row++)
        {
            int step = 2 * (row % (numRows - 1)),
                sIndex = row;
            while (sIndex < len)
            {
                sb.Append(s[sIndex]);
                step = maxStep - step % maxStep;
                sIndex = sIndex + step;
            }
        }
        return sb.ToString();
    }
}
