/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
// TODO: implement with not to reverse list.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverseList(l1);
        ListNode* rl2 = reverseList(l2);

        ListNode* cur = nullptr;
        int carry = 0;
        while(rl1 || rl2 || carry)
        {
            int sum = (rl1?rl1->val:0)+(rl2?rl2->val:0)+carry;
            if(sum>9)
            {
                sum %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            ListNode* tmp = new ListNode(sum);
            tmp->next = cur;
            cur = tmp;
            if(rl1) rl1 = rl1->next;
            if(rl2) rl2 = rl2->next;
        }
        return cur;
    }

private:
    ListNode* reverseList(ListNode* head)
    {
        if(!head->next){return head;}
        ListNode* cur = nullptr;
        ListNode* next = head;

        while(next)
        {
            next = next->next;
            head->next = cur;
            cur = head;
            head = next;
        }

        return cur;
    }
};
// @lc code=end

