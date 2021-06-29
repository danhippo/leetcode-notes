/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
// TODO: Check the Top Voted Solution!!
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){return head;}

        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* nextRun = head;
        while(head && head->next)
        {
            tail->next = head ->next;
            nextRun = head->next->next;
            head->next->next = head;
            tail = head;
            head = nextRun;
        }
        tail->next = head?head:nullptr;
        return dummy.next;
    }
};
// @lc code=end

