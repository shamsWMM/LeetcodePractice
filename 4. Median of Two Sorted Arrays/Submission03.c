#include <stdio.h>

double findMedianSortedArrays(int *x, int xLen, int *y, int yLen)
{
    if (xLen > yLen)
    {
        return findMedianSortedArrays(y, yLen, x, xLen);
    }

    const int LimitValue = 1000001;
    int isOdd = (xLen + yLen) % 2;
    int xStart = 0, xEnd = xLen;
    while (xStart <= xEnd)
    {
        int xPart = (xStart + xEnd) / 2;
        int yPart = (xLen + yLen) / 2 - xPart;

        int xLeft = xPart == 0 ? -LimitValue : x[xPart - 1];
        int xRight = xPart == xLen ? LimitValue : x[xPart];
        int yLeft = yPart == 0 ? -LimitValue : y[yPart - 1];
        int yRight = yPart == yLen ? LimitValue : y[yPart];

        if (xLeft <= yRight && yLeft <= xRight)
        {
            int rightMin = xRight < yRight ? xRight : yRight;
            if (isOdd)
            {
                return rightMin;
            }
            else
            {
                int leftMax = xLeft < yLeft ? yLeft : xLeft;
                return (leftMax + rightMin) / 2.0;
            }
        }
        else if (xLeft > yRight)
        {
            xEnd = xPart - 1;
        }
        else
        {
            xStart = xPart + 1;
        }
    }
    return 0.0;
}

int main()
{
    int nums1[5] = {1, 2, 3, 4, 5};
    int nums2[12] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    double median = findMedianSortedArrays(nums1, 5, nums2, 12);
    printf("Median is: %.1f\n", median);
    return 0;
}