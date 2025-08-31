#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    if (!strsSize) return "";
    if (strsSize == 1) return strs[0];

    char *prefix = calloc(201, sizeof(char));
    char *s = strs[0];
    int sLen = strlen(s);

    for (int i = 0; i < sLen; i++)
    {
        char current = s[i];
        for (int j = 1; j < strsSize; j++)
        {
            if (strs[j][i] != current)
            {
                return prefix;
            }
        }
        prefix[i] = current;
    }
    return prefix;
}