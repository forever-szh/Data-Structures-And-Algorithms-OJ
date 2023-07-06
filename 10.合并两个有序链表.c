#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//�ϲ�������������
//����:https://leetcode.cn/problems/merge-two-sorted-lists/description/
struct ListNode
{
	int val;
	struct ListNode* next;
};
//1.���ж�Ϊ��
//2.�Ż�����Ҫ�ж�Ϊ��

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* head = NULL, * tail = NULL;
	//�������һ������Ϊ�� ������һ��
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	//��ȡһ��С�ĵ��ڵ�һ��
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
	//��һ��Ϊ�յ�ʱ�� 
	//ֱ�Ӱ���һ��ʣ�µĲ��ַŵ�tail����
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


//3,�ڱ�λ ���� �ͷ� ���ùܵ�һ���Ƿ��ǿ�ָ�� ����Ҫ�ͷ�
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* head = NULL, * tail = NULL;
	//�������һ������Ϊ�� ������һ��
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	//�ڱ�λ��ͷ�ڵ� ����һ���������ݵ�ͷ
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
	//�ȴ� ���ͷ�
	//���ͷ� ����Ұָ������
	struct ListNode* list = head->next;
	free(head);
	//head�Ǵ�ͷ�� ���������ͷ ����head����һ��
	return list;
}
