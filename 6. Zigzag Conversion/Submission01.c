#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows <= 1 || len <= 1) {
        char* result = (char*)malloc(len + 1);
        strcpy(result, s);
        return result;
    }
    
    int maxStep = 2 * (numRows - 1);
    char* result = (char*)malloc(len + 1);
    int index = 0;

    for (int row = 0; row < numRows; row++)
    {
        int step = 2 * (row % (numRows - 1)), sIndex = row;
        while(sIndex < len) 
        {
            result[index] = s[sIndex];
            index++;
            step = maxStep - step % maxStep;
            sIndex = sIndex + step;
        }
    }
    result[len] = '\0';
    return result;
}

int main()
{
    char str[] = "12345678";
    char *result = convert(str, 4);
    if (result)
    {
        printf("Longest palindrome: %s\n", result);
        free(result);
    }
    return 0;
}