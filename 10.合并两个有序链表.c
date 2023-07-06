#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//合并两个有序链表
//链接:https://leetcode.cn/problems/merge-two-sorted-lists/description/
struct ListNode
{
	int val;
	struct ListNode* next;
};
//1.有判断为空
//2.优化后不需要判断为空

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* head = NULL, * tail = NULL;
	//如果其中一个链表为空 返回另一个
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	//先取一个小的等于第一个
	if (list1->val < list2->val)
	{
		head = tail = list1;
		list1 = list1->next;
	}
	else
	{
		head = tail = list2;
		list2 = list2->next;
	}
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			tail->next = list1;
			tail = tail->next;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = tail->next;
			list2 = list2->next;
		}
	}
	//当一个为空的时候 
	//直接把另一个剩下的部分放到tail后面
	if (list1)
	{
		tail->next = list1;
	}
	if (list2)
	{
		tail->next = list2;
	}
	return head;
}


//3,哨兵位 开辟 释放 不用管第一个是否是空指针 但需要释放
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* head = NULL, * tail = NULL;
	//如果其中一个链表为空 返回另一个
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	//哨兵位的头节点 开辟一个不存数据的头
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			tail->next = list1;
			tail = tail->next;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = tail->next;
			list2 = list2->next;
		}
	}
	if (list1)
	{
		tail->next = list1;
	}
	if (list2)
	{
		tail->next = list2;
	}
	//先存 后释放
	//先释放 会有野指针问题
	struct ListNode* list = head->next;
	free(head);
	//head是带头的 不是链表的头 返回head的下一个
	return list;
}
