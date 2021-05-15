#pragma once
#include "Common.h"

//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order, and each of their nodes contains a single digit.
//Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
//Output : [7, 0, 8]
//Explanation : 342 + 465 = 807.

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//2021.05.15
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* ans;
	int carry = 0, mod = 0;

	if (l1 && l2)
	{
		carry = (l1->val + l2->val) / 10;
		mod = (l1->val + l2->val) % 10;

		ans = l1;
		ans->val = mod;

		if (carry)
		{
			if (l1->next)
				l1->next->val += carry;
			else if (l2->next)
				l2->next->val += carry;
			else
				l1->next = new ListNode(carry);
		}

		ans->next = addTwoNumbers(l1->next, l2->next);
	}
	else if (l1)
	{
		carry = l1->val / 10;
		mod = l1->val % 10;
		ans = l1;
		ans->val = mod;

		if (carry)
		{
			if (l1->next)
				l1->next->val += carry;
			else
				l1->next = new ListNode(carry);
		}

		ans->next = addTwoNumbers(l1->next, nullptr);
	}
	else if (l2)
	{
		carry = l2->val / 10;
		mod = l2->val % 10;
		ans = l2;
		ans->val = mod;

		if (carry)
		{
			if (l2->next)
				l2->next->val += carry;
			else
				l2->next = new ListNode(carry);
		}

		ans->next = addTwoNumbers(nullptr, l2->next);
	}
	else
	{
		ans = nullptr;
	}
	return ans;
}