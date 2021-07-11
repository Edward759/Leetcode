/* Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
 */

#include "Common.h"

int lengthOfLastWord(string s) 
{
    int len = 0;
    int p = s.length() - 1;

    while(p >= 0 && s[p] == ' ')
        p--;

    while(p >= 0 && s[p] != ' ')
    {
        p--;
        len++;
    }
    return len;
}