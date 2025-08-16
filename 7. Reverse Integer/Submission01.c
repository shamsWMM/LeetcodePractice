#include <stdio.h>
#include <stdint.h>
#include <math.h>

int reverse(int x)
{
    int max = 214748364;
    int rev = 0;
    
    while (x / 10)
    {
        rev = x % 10 + 10 * rev;
        x /= 10;
    }

    if (rev > max || 
        rev < - max ||
        (rev == max && x > 7) ||
        (rev == - max && x < - 8)
    )
    {
            return 0;
    }

    rev = x + 10 * rev;
    return rev;
}

int main()
{
    int num = pow(2,31) - 1;
    num = reverse(num);
    printf("Reverse: %d\n", num);
    return 0;
}