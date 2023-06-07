#define _CRT_SECURE_NO_WARNINGS 1

//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//链表倒数第k个节点

#include <stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

//思路1 遍历两遍
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

//若只能遍历1次
//思路2 双指针
//1 fast先走k步
//2 slow和fast再一起走 fast为空的时候 slow就是倒数第k个
//相当于差距是k个 当fast为空也就是倒数第0个 slow就是倒数第k个
//自己写法
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

//视频写法
//头不是第1个 应该是第0个
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;
	while (k--)
	{
		//k大于链表的长度
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