/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessThan = new ListNode(0);
        ListNode* moreThan = new ListNode(0);
        ListNode* lessThanRoot = lessThan;
        ListNode* moreThanRoot = moreThan;

        while(head)
        {
            if(head->val < x)
            {
                lessThan->next = head;
                lessThan = lessThan->next;
            }
            else
            {
                moreThan->next = head;
                moreThan = moreThan->next;
            }

            head = head->next;
        }

        lessThan->next = moreThanRoot->next;
        moreThan->next = NULL;
        return lessThanRoot->next;
    }
};
// @lc code=end

