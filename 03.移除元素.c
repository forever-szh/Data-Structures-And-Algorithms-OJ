#define _CRT_SECURE_NO_WARNINGS 1


//移除元素 
//链接:https://leetcode.cn/problems/remove-element/
//思路1:找到value 依次挪动覆盖删除 时间复杂度O(N^2) 最坏的情况
//数组中大部分值甚至全部都是value
//
//能否把时间复杂度优化到O(N)
//思路2:一次遍历nums数组 把不是val的值 放到tmp数组 再把tmp数组
//的值拷贝回去 时间复杂度:O(2*N)->O(N) 空间复杂度:O(N)
//
//能否把空间复杂度优化到O(1)
//思路3:src dst
//src去找num数组中不等于val的值 放到dst指向的位置去,再++src,++dst
//相当于标记起始位置 不等于val就赋值 然后往后遍历
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0, dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}
	return dst;
}