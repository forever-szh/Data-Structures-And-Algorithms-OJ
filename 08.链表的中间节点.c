#define _CRT_SECURE_NO_WARNINGS 1

//������м�ڵ�
//https://leetcode.cn/problems/middle-of-the-linked-list/description/


//˼·1 ����һ�� /2 �ٱ���

//��ֻ�ܱ���һ�� ��ô��
//˼·2 ����ָ��
//��ָ��һ��������
//��ָ��һ����һ��
//���������ߵ�β��
//ż�������ߵ�β������һ�� 

#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};

//��ͼ
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
