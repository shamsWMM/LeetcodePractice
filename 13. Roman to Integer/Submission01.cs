public class Solution
{
    public int RomanToInt(string s)
    {
        int sum = 0;
        int length = s.Length;
        char next;

        for (int i = 0; i < length; i++)
        {
            char c = s[i];
            next = i + 1 < length ? s[i + 1] : '\0';

            switch (c)
            {
                case 'M':
                    sum += 1000;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'C':
                    sum += next == 'M' || next == 'D' ? -100 : 100;
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'X':
                    sum += next == 'C' || next == 'L' ? -10 : 10;
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'I':
                    sum += next == 'X' || next == 'V' ? -1 : 1;
                    break;
                default:
                    return 0; // invalid character
            }
        }

        return sum;
    }
}
