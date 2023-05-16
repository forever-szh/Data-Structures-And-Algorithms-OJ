#define _CRT_SECURE_NO_WARNINGS 1

//��ʧ������
//���ӣ�https://leetcode-cn.com/problems/missing-number-lcci/
//˼·1:���� ����qsort ����һ�����ǲ���ǰһ������1 ��ʱ�临�Ӷ�O(n*log2 N)
//˼·2:(0+1+2+3+����+n)-(a[0]+a[1]+a[2]+����+a[n-1]) ʱ�临�Ӷ�O(N)
//˼·3:�����е�ֵ�Ǽ����ڵڼ���λ��дһ�����ֵ O(N)
//˼·4:��һ��ֵx=0
//x�ȸ�0-n������ֵ��� 0���κ�һ�����������Ǹ���
//x�ڸ�������ÿ��ֵ��� ���x����ȱ���Ǹ�����
//����˳�� ֻ����������ͬ�������־ͻ����0 ˵�������Ǹ�x�ͳ�����һ��


//˼·2
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	//��0-n���
	for (int i = 0; i <= numsSize; i++)
	{
		x ^= i;
	}
	//�ٸ���ֵ��ֵ���
	for (int i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	return x;
}