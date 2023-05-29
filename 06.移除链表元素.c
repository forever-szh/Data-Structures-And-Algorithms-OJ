#define _CRT_SECURE_NO_WARNINGS 1

//移除链表元素
//指定一个值 删除所有的值

//找到那个值 找到前一个
//https://leetcode.cn/problems/remove-linked-list-elements/description/

//调试代码
#include <stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};

//答案
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL, * cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			//头删 没有prev prev为空指针 空指针解引用非法访问
			if (cur == head)
			{
				//把第二个变成头部
				head = cur->next;
				//删除第一个
				free(cur);
				//再把第二个变为cur
				cur = head;
			}
			else
			{
				//先指向下一个
				prev->next = cur->next;
				//删除
				free(cur);
				//再把cur变为删除的下一个
				cur = prev->next;
			}
		}
		else
		{
			//迭代往后走
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//调试代码
int main()
{
	//开辟节点
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	//给值
	n1->val = 7;
	n1->next = n2;
	n2->val = 7;
	n2->next = NULL;
}