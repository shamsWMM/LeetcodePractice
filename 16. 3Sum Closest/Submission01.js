/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const threeSumClosest = function(nums, target) {
    let sortedNums = nums.toSorted((num1, num2) => num1 - num2);

    if (sortedNums.length === 3 || target >= 3 * sortedNums[sortedNums.length - 1])
        return sortedNums.slice(-3).reduce((sum, num) => sum + num, 0);

    let threeNumsSum = sortedNums
        .slice(0, 3)
        .reduce((sum, num) =>  sum + num, 0);

    if (target <= 3 * sortedNums[0] || target === threeNumsSum)
        return threeNumsSum;

    for (let leftIndex = 0; leftIndex < sortedNums.length - 2; leftIndex++)
        {
            let middleIndex = leftIndex + 1;
            let rightIndex = sortedNums.length - 1;
            
            while (middleIndex < rightIndex) {
                const currentSum = sortedNums[leftIndex] + sortedNums[middleIndex] + sortedNums[rightIndex];

                if (currentSum === target)
                    return currentSum;

                let distanceComparison = (threeNumsSum - target) ** 2 - (currentSum - target) ** 2;

                threeNumsSum = distanceComparison >= 0 ? currentSum : threeNumsSum;
                
                if(target > currentSum) {
                    middleIndex++;
                }
                else {
                    rightIndex--;
                }
            }
        }
    return threeNumsSum;
};