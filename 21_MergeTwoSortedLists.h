/* Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4] */

#include "Common.h"

//2021.6.6
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;

        ListNode* newHead;
        if(l1->val < l2->val)
        {
            newHead = l1;
            l1 = l1->next;
        }
        else
        {
            newHead = l2;
            l2 = l2->next;
        }
        
        ListNode* p = newHead;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if(l1)
            p->next = l1;
        if(l2)
            p->next = l2;

        return newHead;
        
    }