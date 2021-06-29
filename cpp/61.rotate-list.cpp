/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int length = 1;
        ListNode* tail = head;
        while(tail->next)
        {
            tail = tail->next;
            length++;
        }
        k %= length;
        if(k==0){return head;}
        ListNode* prev = head;
        while(--length>k) prev = prev->next;

        ListNode* newHead = prev->next;
        prev->next = nullptr;
        tail->next = head;

        return newHead;
    }
};
// @lc code=end

