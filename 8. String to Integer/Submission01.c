#include <stdio.h>
#include <stdint.h>

int myAtoi(char *s);
int processLargeNumber(int s, int next, int num);

int myAtoi(char *s)
{
    int index = 0, sign = 0, result = 0, current;

    // identify valid digits
    while (s && *s && index < 9)
    {
        current = *s;
        if (!sign && !index && current == ' ') // leading space
            ;
        else if (!sign && !index && (current == '-' || current == '+')) // leading sign
        {
            sign = 44 - current;
        }
        else if (!index && current == '0') // leading zero
        {
            index = 0;
            sign = sign == -1 ? sign : 1; // flag progress
        }
        else if (current >= '0' && current <= '9') // valid character
        {
            result = 10 * result + current - '0';
            index++;
        }
        else // invalid character
        {
            break;
        }
        s++;
    }

    result = !sign ? result : sign * result;

    // check boundary cases
    current = *s;
    if (index == 9 && current >= '0' && current <= '9')
    {
        current -= '0';
        int nextExits = *(s + 1) >= '0' && *(s + 1) <= '9';
        result = processLargeNumber(current, nextExits, result);
    }

    return result;
}

int processLargeNumber(int current, int nextExists, int num)
{
    int max = 214748364;
    if (
        nextExists ||
        num > max ||
        num < -max ||
        (num == max && current > 7) ||
        (num == -max && current > 8))
    {
        return num < 0 ? -max * 10 - 8 : max * 10 + 7;
    }

    return num < 0 ? num * 10 - current : num * 10 + current;
}

int main()
{
    char *num = "2147483646";
    int result = myAtoi(num);
    printf("Result: %d\n", result);
    return 0;
}