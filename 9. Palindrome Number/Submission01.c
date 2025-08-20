#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int x) {
    int intermediateX = x, reverseX = 0, count = 0;
    while (intermediateX > 0 && count < 9)
    {
        reverseX = 10 * reverseX + intermediateX % 10;
        intermediateX /= 10;
        count++;
    }

    if (count < 9)
    {
        return x == reverseX;
    }
    
    return x % 10 == intermediateX && x / 10 == reverseX;
}

int main()
{
    int num = 1000000001;

    int result = isPalindrome(num);
    
    printf("Result: %d\n", result);

    return 0;
}