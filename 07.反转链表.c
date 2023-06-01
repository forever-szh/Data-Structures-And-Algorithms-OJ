#define _CRT_SECURE_NO_WARNINGS 1

//反转链表
//https://leetcode.cn/problems/reverse-linked-list/description/

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//答案
//思路1
struct ListNode* reverseList(struct ListNode* head)
{
	//空链表就直接返回空
	if (head == NULL)
		return NULL;
	//不是空链表 画图分析
	struct ListNode* n1, * n2, * n3;
	n1 = NULL;
	n2 = head;
	n3 = head->next;
	while (n2)
	{
		//反转
		n2->next = n1;
		//迭代往后走
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

//头插
//思路2
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
		return NULL;
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = head->next;
	while (cur)
	{
		//头插
		cur->next = newhead;
		//迭代
		newhead = cur;
		cur = next;
		if (next)
			next = cur->next;
	}
	return newhead;
}