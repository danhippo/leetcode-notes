/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i>=0;i--)
        {
            int sum = digits[i]+carry;
            if(sum<10)
            {
                digits[i]=sum;
                return digits;
            }
            else
            {
                sum%=10;
                digits[i] = sum;
            }
        }
        digits.insert(digits.begin(),carry);
        return digits;
    }
};
// @lc code=end

