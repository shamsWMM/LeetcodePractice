#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int **threeSum(int *nums, int numsSize, int *resultSize, int **resultColumnSizes);
int findTargetIndex(int left, int right, int target, int *nums);
void resizeResult(int resultSize, int **resultColumnSizes, int ***result, int *tempSize);
void addTriplet(int left, int middle, int right, int resultSize, int **resultColumnSizes, int ***result);
int compare(const void *num1, const void *num2);

int main()
{
    int nums[] = {-1,-1,-1,-1,0,0,0,1,1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int resultSize = 0;
    int *resultColumnSizes = NULL;

    int **result = threeSum(nums, numsSize, &resultSize, &resultColumnSizes);

    for (int i = 0; i < resultSize; i++)
    {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
    }

    for (int i = 0; i < resultSize; i++)
    {
        free(result[i]);
    }
    free(result);
    free(resultColumnSizes);

    return 0;
}

int **threeSum(int *nums, int numsSize, int *resultSize, int **resultColumnSizes)
{
    *resultSize = 0;
    if (numsSize < 3) return NULL;

    int tempSize = numsSize;
    qsort(nums, numsSize, sizeof(int), compare);
    *resultColumnSizes = malloc(sizeof(int) * tempSize);
    int **result = malloc(sizeof(int *) * tempSize);
    int left = 0, maxRight = numsSize - 1, right = maxRight, maxMiddle = left + 1;

    while (left <= maxMiddle && nums[left] <= 0)
    {
        if (left > 0 && nums[left] == nums[left-1])
        {
            left++;
            continue;
        }

        while (maxRight > left + 2 && nums[maxRight] > - 2 * nums[left]) maxRight--;
        while (maxMiddle < maxRight - 1 && nums[maxMiddle] < -2 * nums[left] / 3) maxMiddle++;

        right = maxRight;
        while (right > left + 1)
        {
            if (right < numsSize - 1 && nums[right + 1] == nums[right])
            {
                right--;
                continue;
            }
            int target = -nums[left] - nums[right];
            int middle = findTargetIndex(left + 1, right - 1, target, nums);
            if(middle > 0) addTriplet(nums[left], nums[middle], nums[right], ++(*resultSize), resultColumnSizes, &result);
            if(tempSize - *resultSize < 1) resizeResult(*resultSize, resultColumnSizes, &result, &tempSize);
            right--;
        }
        left++;
    };

    return result;
}

int compare(const void *num1, const void *num2)
{
    return *((int *)num1) - *((int *)num2);
}

void addTriplet(int left, int middle, int right,
                int resultSize,
                int **resultColumnSizes,
                int ***result)
{
    (*resultColumnSizes)[resultSize - 1] = 3;
    (*result)[resultSize - 1] = (int *)malloc(sizeof(int) * 3);
    (*result)[resultSize - 1][0] = left;
    (*result)[resultSize - 1][1] = middle;
    (*result)[resultSize - 1][2] = right;
}

void resizeResult(int resultSize, int **resultColumnSizes, int ***result, int *tempSize)
{
    *tempSize *= 2;
    *result = realloc(*result, sizeof(int *) * (*tempSize));
    *resultColumnSizes = realloc(*resultColumnSizes, sizeof(int) * (*tempSize));
}

int findTargetIndex(int left, int right, int target, int *nums)
{
    int middle;
    do
    {
        middle = left + (right - left + 1) / 2;
        if (nums[middle] > target) right = middle - 1;
        else if (nums[middle] < target) left = middle + 1;
        else return middle;
    }
    while (left <= right);

    return -1;
}