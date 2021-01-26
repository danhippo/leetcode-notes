/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include<stdint.h>

class Solution {
public:
    bool isPalindrome(int x) {
        int ori = x;

        if(x<0)
        {
            return false;
        }
        else
        {
            int64_t tmp = 0;
            while(x!=0)
            {
                tmp = tmp * 10 + x % 10;
                x/=10;
            }
            return tmp==(int32_t)tmp?ori==tmp:false;
        }
    }
};
// @lc code=end

