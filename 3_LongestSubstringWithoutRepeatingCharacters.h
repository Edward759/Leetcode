#pragma once

#include "Common.h"
// Given a string s, find the length of the longest substring without repeating characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.


//2021.05.16
int lengthOfLongestSubstring(string s)
{
        if(s.length() < 2)
            return s.length();

        int curLen = 0, maxLen = 0;
        map<char, int>lastPos;

        for(int i = 0; i < s.length(); i++)
        {
            if(lastPos.find(s[i]) == lastPos.end() || i - lastPos[s[i]] > curLen)
            {
                curLen++;
            }
            else
            {
                curLen = i - lastPos[s[i]];
            }

            lastPos[s[i]] = i;

            if(curLen > maxLen)
                maxLen = curLen;
        }

        return maxLen;
}