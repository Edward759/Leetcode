/* 
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
 */

#include "Common.h"

string longestCommonPrefix(vector<string>& strs) 
{
    string ans = strs[0];

    for(int i = 1; i <strs.size(); ++i)
    {
        string tmp = strs[i];
        int j = 0;
        for(; j < ans.length() && j < tmp.length(); ++j)
        {
            if(ans[j] != tmp[j])
                break;
        }
        ans = ans.substr(0, j);
        if(ans == "")
            break;
    }
    return ans;
}