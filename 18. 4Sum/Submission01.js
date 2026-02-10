/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */

var fourSum = function(nums, target) {
    const sorted = nums.toSorted((a, b) => a - b);
    const result = [];
    
    for (let i = 0; i < sorted.length - 3; i++) {
        if (i > 0 && sorted[i] === sorted[i - 1]) continue;

        for (let j = i + 1; j < sorted.length - 2; j++) {
            if (j > i + 1 && sorted[j] === sorted[j - 1]) continue;

            let left = j + 1;
            let right = sorted.length - 1;

            while (left < right) {
                const sum = sorted[i] + sorted[j] + sorted[left] + sorted[right];

                if (sum === target) {
                    result.push([sorted[i], sorted[j], sorted[left], sorted[right]]);

                    while (left < right && sorted[left] === sorted[left + 1]) left++;
                    while (left < right && sorted[right] === sorted[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}