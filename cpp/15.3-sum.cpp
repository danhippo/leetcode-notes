/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int first = 0; first < nums.size(); first++)
        {
            if(nums[first] > 0)
            {
                break;
            }

            if(first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int second = first + 1;
            int third = nums.size() - 1;
            while(third > second)
            {
                //printf("%d, %d, %d\n", first, second, third);
                /*
                if(second != first + 1 && nums[second] == nums[second - 1])
                {
                    ++second;
                }
                if(third != nums.size() - 1 && nums[third] == nums[third + 1])
                {
                    --third;
                }
                */
                if (nums[second]+nums[third]+nums[first] == 0)
                {
                    printf("Add :%d, %d, %d\n", first, second, third);
                    vector<int> item {nums[first], nums[second], nums[third]};
                    result.push_back(item);
                    while(second < nums.size() - 1 && nums[second] == nums[second + 1])
                    {
                        ++second;
                    }
                    while(third > 0 && nums[third] == nums[third - 1])
                    {
                        --third;
                    }
                    ++second;
                    --third;
                }

                else if(nums[second]+nums[third]+nums[first] > 0) --third;
                else ++second;
            }
        }
        return result;
    }
};
// @lc code=end

