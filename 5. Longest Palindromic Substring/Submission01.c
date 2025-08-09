#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s)
{
    if (!s || !s[0]) return "";
    if (!s[1]) return s;

    int maxEven = 0, indexEven = 0, max = 1, index = 0, sLen = strlen(s);
    for (int i = 1; i < sLen; i++)
    {
        int leftEven = i - 1, rightEven = i, leftOdd = i - 1, rightOdd = i + 1;
        while (leftEven >= 0 && rightEven < sLen && s[leftEven] == s[rightEven])
        {
            if (rightEven - leftEven + 1 > maxEven)
            {
                indexEven = leftEven;
                maxEven = rightEven - leftEven + 1;
            }
            leftEven--;
            rightEven++;
        }
        while (leftOdd >= 0 && rightOdd < sLen && s[leftOdd] == s[rightOdd])
        {
            if (rightOdd - leftOdd + 1 > max)
            {
                index = leftOdd;
                max = rightOdd - leftOdd + 1;
            }
            leftOdd--;
            rightOdd++;
        }
    }

    if (maxEven > max)
    {
        index = indexEven;
        max = maxEven;
    }

    char *result = (char *)malloc((max + 1) * sizeof(char));
    strncpy(result, s + index, max);
    result[max] = '\0';
    return result;
}

int main()
{
    char str[] = "shamsmahs";

    char *palindrome = longestPalindrome(str);
    if (palindrome)
    {
        printf("Longest palindrome: %s\n", palindrome);
        free(palindrome);
    }
    return 0;
}