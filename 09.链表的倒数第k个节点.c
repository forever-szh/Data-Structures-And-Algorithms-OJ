#define _CRT_SECURE_NO_WARNINGS 1

//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//��������k���ڵ�

#include <stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

//˼·1 ��������
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	// write code here	
	int count = 0;
	struct ListNode* cur = pListHead;
	struct ListNode* n = pListHead;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	if (k > count)
	{
		return NULL;
	}
	for (int i = 0; i < count - k; i++)
	{
		n = n->next;
	}
	return n;
}

//��ֻ�ܱ���1��
//˼·2 ˫ָ��
//1 fast����k��
//2 slow��fast��һ���� fastΪ�յ�ʱ�� slow���ǵ�����k��
//�൱�ڲ����k�� ��fastΪ��Ҳ���ǵ�����0�� slow���ǵ�����k��
//�Լ�д��
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	int count = 0;
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;
	for (int i = 0; i < k; i++)
	{
		if (fast)
			fast = fast->next;
		else
			count = 1;
	}
	if (count == 1 || k == 0 || pListHead == NULL)
		return NULL;
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//��Ƶд��
//ͷ���ǵ�1�� Ӧ���ǵ�0��
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;
	while (k--)
	{
		//k��������ĳ���
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}