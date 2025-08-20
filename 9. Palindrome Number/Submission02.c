#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int x) {

    if (x < 10) return x >= 0;
    
    int divisor = 1000000000;
    while (x < divisor) divisor /= 10;

    while (divisor)
    {
        if (x / divisor != x % 10) return 0;
        x = x % divisor / 10;
        divisor /= 100;
    }
    
    return 1;
}

int main()
{
    int num = 121;

    int result = isPalindrome(num);
    
    printf("Result: %d\n", result);

    return 0;
}