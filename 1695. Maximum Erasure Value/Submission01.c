#include <stdio.h>

void printArray(int* arr, int size);
int maximumUniqueSubarray(int* nums, int numsSize);

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], i < size - 1 ? ", " : "");
    }
    printf("]\n");
}

int maximumUniqueSubarray(int* nums, int numsSize) {
    if (!nums) {
        fprintf(stderr, "Error: Input array is NULL\n");
        return 0;
    }
    
    // Early return for edge cases
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int l = 0, r = 0, max = 0, c = 0, seen[10001] = {0};

    while(r < numsSize)
    {
        while(seen[nums[r]])
        {
            c -= nums[l];
            seen[nums[l]] = 0;
            l++;
        }

        seen[nums[r]] = 1;
        c += nums[r];
        max = (c > max) ? c : max;
        r++;
    }
    return max;
}

int main() {
    int arr1[] = {2, 4, 3, 2, 10, 20, 1, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test 1: ");
    printArray(arr1, size1);
    printf("Result: %d\n\n", maximumUniqueSubarray(arr1, size1));
    return 0;
}