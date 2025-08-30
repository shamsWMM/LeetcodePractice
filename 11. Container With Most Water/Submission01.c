#include <stdio.h>

int maxArea(int* height, int heightSize) 
{
    int *right = height + heightSize - 1;
    int maxArea = 0;

    while (height < right)
    {
        int area = (right - height) * (*height < *right ? *height : *right);
        maxArea = area > maxArea ? area : maxArea;
        if (*height < *right)
        {
            height++;
        }
        else
        {
            right--;
        }
    }
    return maxArea;
}

int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, heightSize);
    
    printf("Result: %d\n", result);

    return 0;
}