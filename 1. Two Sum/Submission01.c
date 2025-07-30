#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TABLE_SIZE 10007

int hash(int key){
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

void insert(int* keys, int* values, int* seen,
int key, int value){
    int index = hash(key);
    while(seen[index]){
        index = (index + 1) % TABLE_SIZE;
    }
    seen[index] = 1;
    keys[index] = key;
    values[index] = value;
}

int search(int* keys, int* values, int* seen, int key){
    int index = hash(key);
    while (seen[index]){
        if (keys[index] == key){
            return values[index];
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* keys = malloc(TABLE_SIZE * sizeof(int));
    int* values = malloc(TABLE_SIZE * sizeof(int));
    int* seen = calloc(TABLE_SIZE, sizeof(int));
    int* result = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++){
        int complement = target - nums[i];
        int found = search(keys, values, seen, complement);
        if(found != -1){
            result[0] = i;
            result[1] = found;
            *returnSize = 2;
            free(keys);
            free(values);
            free(seen);
            return result;
        }
        insert(keys, values, seen, nums[i], i);
    }
    *returnSize = 0;
    free(keys);
    free(values);
    free(seen);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 18
    ;
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}