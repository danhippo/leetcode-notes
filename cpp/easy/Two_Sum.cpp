#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();

        vector<int>::iterator it;
        map<int, int> mapNum;
        vector<int> dst;
        int index = 0;
        for(it=begin; it != end; it++, index++)
        {
            int res = target - *it;
            map<int, int>::iterator iter = mapNum.find(res);
            if(iter!=mapNum.end())
            {
                dst.push_back(index);
                dst.push_back(iter->second);
                return dst;
            }
            mapNum[*it] = index;
        }
        throw invalid_argument("two sum solution not found");
    }
};
