#include "Common.h"

int romanToInt(string s) 
{
        map<char, int> roman =
         {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        
        int i = s.size() - 1;
        int j = i - 1;
        int ans = roman[s[i]];
        while(j >= 0)
        {
            int num1 = roman[s[i]];
            int num2 = roman[s[j]];
            ans += (num1 <= num2 ? num2 : -num2);
            i--;
            j--;
        }
        return ans;
    }