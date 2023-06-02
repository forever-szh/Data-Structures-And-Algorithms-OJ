#define _CRT_SECURE_NO_WARNINGS 1

//链表的中间节点
//https://leetcode.cn/problems/middle-of-the-linked-list/description/


//思路1 遍历一遍 /2 再遍历

//若只能遍历一次 怎么办
//思路2 快慢指针
//快指针一次走两步
//慢指针一次走一步
//奇数个是走到尾部
//偶数个是走到尾部的下一个 

#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};

//画图
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
