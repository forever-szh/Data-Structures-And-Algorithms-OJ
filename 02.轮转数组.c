#define _CRT_SECURE_NO_WARNINGS 1

//旋转数组
//链接:https://leetcode-cn.com/problems/rotate-array/
//思路1:暴力求解，旋转K次
//时间复杂度:O(N*K) 空间复杂度O(1)
//思路2:开辟额外空间
//时间复杂度:O(N) 空间复杂度:O(N)
//思路3:
//前n-k个逆置
//后k个逆置
//整体逆置

//思路3

void Reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		++left;
		--right;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	if (k >= numsSize)
		k %= numsSize;
	//前n-k个数逆置
	Reverse(nums, 0, numsSize - k - 1);
	//后k个逆置
	Reverse(nums, numsSize - k, numsSize - 1);
	//整体逆置
	Reverse(nums, 0, numsSize - 1);
}
//k==n时 不旋转就是要的结果