/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6. */

#include "Common.h"

//2021.7.4
int maxSubArray(vector<int>& nums) 
{
    int curSum = 0, maxSum = INT_MIN;

    for(int i = 0; i < nums.size(); ++i)
    {
        curSum += nums[i];
        if(curSum < nums[i])
            curSum = nums[i];
        if(curSum >= maxSum)
            maxSum = curSum;
    }
    return maxSum;
}