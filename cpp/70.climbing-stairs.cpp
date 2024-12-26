/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int prev1  = 2; int prev2 = 1;
        for(int i = 3; i <= n;i++)
        {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
        
    }
};
// @lc code=end

