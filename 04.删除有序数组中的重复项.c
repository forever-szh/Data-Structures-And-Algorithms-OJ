#define _CRT_SECURE_NO_WARNINGS 1

//ɾ�����������е��ظ���
//����:https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

//ȥ�� ��ָ�� ���±� ��ͼ
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
	//����������������ظ��� ��ʱ��i��¼�ľ��ǵ�һ����
	nums[dst] = nums[i];
	//dst��ʱΪ�±�
	++dst;
	//dst��Ϊǰ������ݸ��� 
	return dst;
}