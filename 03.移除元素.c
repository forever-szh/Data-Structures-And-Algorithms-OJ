#define _CRT_SECURE_NO_WARNINGS 1


//�Ƴ�Ԫ�� 
//����:https://leetcode.cn/problems/remove-element/
//˼·1:�ҵ�value ����Ų������ɾ�� ʱ�临�Ӷ�O(N^2) ������
//�����д󲿷�ֵ����ȫ������value
//
//�ܷ��ʱ�临�Ӷ��Ż���O(N)
//˼·2:һ�α���nums���� �Ѳ���val��ֵ �ŵ�tmp���� �ٰ�tmp����
//��ֵ������ȥ ʱ�临�Ӷ�:O(2*N)->O(N) �ռ临�Ӷ�:O(N)
//
//�ܷ�ѿռ临�Ӷ��Ż���O(1)
//˼·3:src dst
//srcȥ��num�����в�����val��ֵ �ŵ�dstָ���λ��ȥ,��++src,++dst
//�൱�ڱ����ʼλ�� ������val�͸�ֵ Ȼ���������
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