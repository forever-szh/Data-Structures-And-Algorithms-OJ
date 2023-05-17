#define _CRT_SECURE_NO_WARNINGS 1

//��ת����
//����:https://leetcode-cn.com/problems/rotate-array/
//˼·1:������⣬��תK��
//ʱ�临�Ӷ�:O(N*K) �ռ临�Ӷ�O(1)
//˼·2:���ٶ���ռ�
//ʱ�临�Ӷ�:O(N) �ռ临�Ӷ�:O(N)
//˼·3:
//ǰn-k������
//��k������
//��������

//˼·3

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
	//ǰn-k��������
	Reverse(nums, 0, numsSize - k - 1);
	//��k������
	Reverse(nums, numsSize - k, numsSize - 1);
	//��������
	Reverse(nums, 0, numsSize - 1);
}
//k==nʱ ����ת����Ҫ�Ľ��