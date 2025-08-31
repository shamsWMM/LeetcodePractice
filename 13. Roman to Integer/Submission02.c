#include <stdio.h>

int romanToInt(char *s) {
    int sum = 0;
    char previous = '\0';
    
    while(s && *s)
    {
        switch (*s)
        {
            case 'M':
                sum += previous == 'C' ? 800 : 1000;
                break;
            case 'D':
                sum += previous == 'C' ? 300 : 500;
                break;
            case 'C':
                sum += previous == 'X' ? 80 : 100;
                break;
            case 'L':
                sum += previous == 'X' ? 30 : 50;
                break;
            case 'X':
                sum += previous == 'I' ? 8 : 10;
                break;
            case 'V':
                sum += previous == 'I' ? 3 : 5;
                break;
            case 'I':
                sum += 1;
                break;
            default:
                return 0; // invalid character
        }
        previous = *s;
        s++;
    }

    return sum;
}

int main()
{
    char *num = "MCMXCIV";

    int result = romanToInt(num);
    
    printf("Result: %d\n", result);

    return 0;
}