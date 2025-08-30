#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int increments[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char *result = calloc(20, sizeof(char));
    int value = 0;

    for(int i = 0; i < 13; i++) 
    {
        value = num / increments[i];
        num = num % increments[i];
        for (int j = 0; j < value; j++) 
        {
            strcat(result, symbols[i]);
        }
    }
    
    return result;
}

int main()
{
    int num = 1994;

    char *result = intToRoman(num);
    
    printf("Result: %s\n", result);

    free(result);
    return 0;
}