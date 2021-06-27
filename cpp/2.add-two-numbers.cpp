/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(! l2) {return l1;}
        if(! l1) {return l2;}
        ListNode* root = new ListNode(0);
        ListNode* current = root;
        int carry=0;
        while(l1||l2||carry)
        {
            int sum = (l1?l1->val:0)+(l2?l2->val:0)+carry;
            if(sum>9)
            {
                sum -=10;
                carry=1;
            }
            else
            {
                carry=0;
            }

            current->next = new ListNode(sum);
            current = current->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return root->next;

    }
};
// @lc code=end

