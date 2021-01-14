/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include<stdint.h>

class Solution {
public:
    int reverse(int x) {
        int64_t tmp = 0;
        while(x!=0)
        {
            tmp = tmp*10 + x%10;
            x/=10;
        }
        return tmp==(int32_t)tmp? tmp:0;
    }
};
// @lc code=end

