public class Solution
{
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        const int MaxValue = 1000001;
        int l1 = nums1.Length,
            l2 = nums2.Length;

        if (l2 < l1)
        {
            return FindMedianSortedArrays(nums2, nums1);
        }

        int nums1Start = 0,
            nums1End = l1,
            nums1Part,
            nums2Part;

        while (nums1Start <= nums1End)
        {
            nums1Part = (nums1Start + nums1End) / 2;
            nums2Part = (l1 + l2 + 1) / 2 - nums1Part;

            int nums1LeftLast = nums1Part == 0 ? -MaxValue : nums1[nums1Part - 1];
            int nums1RightFirst = nums1Part == l1 ? MaxValue : nums1[nums1Part];
            int nums2LeftLast = nums2Part == 0 ? -MaxValue : nums2[nums2Part - 1];
            int nums2RightFirst = nums2Part == l2 ? MaxValue : nums2[nums2Part];

            if (nums1LeftLast <= nums2RightFirst && nums2LeftLast <= nums1RightFirst)
            {
                int maxLeft = nums1LeftLast >= nums2LeftLast ? nums1LeftLast : nums2LeftLast;
                if ((l1 + l2) % 2 == 1)
                    return maxLeft;

                int minRight =
                    nums1RightFirst <= nums2RightFirst ? nums1RightFirst : nums2RightFirst;
                return (maxLeft + minRight) / 2.0;
            }
            else if (nums1LeftLast > nums2RightFirst)
            {
                nums1End = nums1Part - 1;
                ;
            }
            else
            {
                nums1Start = nums1Part + 1;
            }
        }
        return -MaxValue;
    }
}
