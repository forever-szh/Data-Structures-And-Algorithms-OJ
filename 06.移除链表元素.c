#define _CRT_SECURE_NO_WARNINGS 1

//�Ƴ�����Ԫ��
//ָ��һ��ֵ ɾ�����е�ֵ

//�ҵ��Ǹ�ֵ �ҵ�ǰһ��
//https://leetcode.cn/problems/remove-linked-list-elements/description/

//���Դ���
#include <stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};

//��
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL, * cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			//ͷɾ û��prev prevΪ��ָ�� ��ָ������÷Ƿ�����
			if (cur == head)
			{
				//�ѵڶ������ͷ��
				head = cur->next;
				//ɾ����һ��
				free(cur);
				//�ٰѵڶ�����Ϊcur
				cur = head;
			}
			else
			{
				//��ָ����һ��
				prev->next = cur->next;
				//ɾ��
				free(cur);
				//�ٰ�cur��Ϊɾ������һ��
				cur = prev->next;
			}
		}
		else
		{
			//����������
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//���Դ���
int main()
{
	//���ٽڵ�
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	//��ֵ
	n1->val = 7;
	n1->next = n2;
	n2->val = 7;
	n2->next = NULL;
}