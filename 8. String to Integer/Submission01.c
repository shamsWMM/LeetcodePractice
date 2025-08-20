#include <stdio.h>
#include <stdint.h>

int myAtoi(char *s);
int processLargeNumber(int index, int tenthDigit, int num); 

int myAtoi(char *s)
{
    int index = 0, sign = 0, current;
    int digits[200] = {0};

    // identify valid digits
    while (s && *s)
    {
        current = *s;
        if (!sign && !index && current == 32); // leading space
        else if (!sign && !index && (current == 43 || current == 45)) // leading sign
        {
            sign = current;
        }
        else if(!index && current == 48) // leading zero
        {
            index = 0;
            sign = sign == 45 ? 45 : 43; // flag progress
        }
        else if(current >= 48 && current <= 57) // valid character
        {
            digits[index++] = current - 48;
        }
        else // invalid character
        {
            break;
        }
        s++;
    }

    // process number up to max
    int result = 0;
    for (int i = 0; i < index && i < 9; i++)
    {
        result = 10 * result + digits[i];
    }

    // add sign
    result = sign == 45 ? -1 * result : result;

    // check boundary cases
    if (index > 9)
    {
        result = processLargeNumber(index, digits[9], result);
    }

    return result;
}

int processLargeNumber(int index, int tenthDigit, int num)
{
    int max = 214748364;
    if ((index > 10 && num > 0) || num > max || (num == max && tenthDigit > 7))
    {
        return max * 10 + 7;
    }
    else if(index > 10 || num < - max || (num == - max && tenthDigit > 8)
    )
    {
        return - max * 10 - 8;
    }
    tenthDigit = num < 0 ? -1 * tenthDigit : tenthDigit;
    return num * 10 + tenthDigit;
}

int main()
{
    char* num = "1337c0d3";
    int result = myAtoi(num);
    printf("Result: %d\n", result);
    return 0;
}