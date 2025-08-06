#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    if (totalSize == 0) {
        return 0.0;
    }

    if (totalSize == 1) {
        return nums1Size ? *nums1 : *nums2;
    }

    int isOdd = totalSize % 2;
    int halfSize = totalSize / 2;
    int m[2] = {0, 0}, val = 0;
    double result = 0.0;
    for(int i = 0; i < halfSize + 1; i++) {
        if (nums1 && nums1Size && (!nums2Size || *nums2 > *nums1)){
            val = *nums1;
            nums1++;
            nums1Size--;
        }
        else if (nums2Size){
            val = *nums2;
            nums2++;
            nums2Size--;
        }
        else {
            break;
        }
        m[i % 2] = val;
    }

    result =  isOdd ? m[halfSize%2] : (m[0] + m[1]) / 2.0;
    return result;
}

int main() {
    int nums1[5] = {1,2,3,4,5};
    int nums2[12] = {6,7,8,9,10,11,12,13,14,15,16,17};
    double median = findMedianSortedArrays(nums1, 5, nums2, 12);
    printf("Median is: %.1f\n", median);
    return 0;
}