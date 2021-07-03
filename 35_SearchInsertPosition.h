/* Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2 */

#include "Common.h"

//2021.7.3
int searchInsert(vector<int>& nums, int target) 
{
    int left = 0, right = nums.size() - 1;
    int mid = 0;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            return mid;
    }

    mid = (left + right) / 2;
    if(nums[mid] > target)
        return mid;
    if(nums[mid] < target)
        return mid + 1;

    return mid;
}