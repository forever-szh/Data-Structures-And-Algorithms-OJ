#define _CRT_SECURE_NO_WARNINGS 1

//��ת����
//https://leetcode.cn/problems/reverse-linked-list/description/

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//��
//˼·1
struct ListNode* reverseList(struct ListNode* head)
{
	//�������ֱ�ӷ��ؿ�
	if (head == NULL)
		return NULL;
	//���ǿ����� ��ͼ����
	struct ListNode* n1, * n2, * n3;
	n1 = NULL;
	n2 = head;
	n3 = head->next;
	while (n2)
	{
		//��ת
		n2->next = n1;
		//����������
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

//ͷ��
//˼·2
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
		return NULL;
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = head->next;
	while (cur)
	{
		//ͷ��
		cur->next = newhead;
		//����
		newhead = cur;
		cur = next;
		if (next)
			next = cur->next;
	}
	return newhead;
}