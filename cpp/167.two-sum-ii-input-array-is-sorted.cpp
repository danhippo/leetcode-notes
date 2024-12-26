/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> dst;
        while(left < right)
        {
            if(numbers[left] + numbers[right] > target)
                right--;
            else if(numbers[left] + numbers[right] < target)
                left++;
            else
            {
                dst.push_back(left+1);
                dst.push_back(right+1);
                return dst;
            }
        }
        return dst;
    }
};
// @lc code=end

