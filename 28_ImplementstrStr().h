/* Implement strStr().

Return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? 
This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2 */

#include "Common.h"

int strStr(string haystack, string needle) 
{
    if(needle == "")
        return 0;
    
    for(int i = 0; i < haystack.length(); ++i)
    {
        int j = i, k = 0;
        while(j < haystack.length() && needle[k] == haystack[j])
        {
            j++;
            k++;
        }
        if(k == needle.length())
            return j - needle.length();
    }

    return -1;
}