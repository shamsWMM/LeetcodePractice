int compare(const void *num1, const void *num2);

int findGCD(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int min = nums[0];
    int max = nums[numsSize - 1];
    int temp;
    while (min > 0)
    {
        temp = max % min;
        max = min;
        min = temp;
    }

    return max;
}

int compare(const void *num1, const void *num2)
{
    return *((int *)num1) - *((int *)num2);
}