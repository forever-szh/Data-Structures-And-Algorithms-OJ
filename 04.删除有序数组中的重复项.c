#define _CRT_SECURE_NO_WARNINGS 1

//删除有序数组中的重复项
//链接:https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

//去重 三指针 三下标 画图
//1.nums[i]==nums[j]
//++j
//2.nums[i]!=nums[j]
//nums[dst]=nums[i]
//++dst
//i=j
//++j


int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}
	int i = 0;
	int j = 1;
	int dst = 0;
	while (j < numsSize)
	{
		if (nums[i] == nums[j])
		{
			++j;
		}
		else
		{
			nums[dst] = nums[i];
			++dst;
			i = j;
			++j;
		}
	}
	//可能最后两个数是重复的 这时候i记录的就是第一个数
	nums[dst] = nums[i];
	//dst此时为下标
	++dst;
	//dst就为前面的数据个数 
	return dst;
}