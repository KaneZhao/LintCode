#ifndef C824_H
#define C824_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �䵥���� IV
*
* �������飬����һ��������һ���⣬���������������Σ��������г������ε��������š����ҳ��ҳ��Ǹ�����һ�ε�����
* ע������
* 1 <= nums.length < 10^4
* Ϊ��Լ�������ʱ�临�Ӷȣ���ĳ��򽫻����� 10^5 ��
* ����
* ���� nums = [3,3,2,2,4,5,5], ���� 4��
* ���ͣ�
* 4 ֻ������һ�Ρ�
* ���� nums = [2,1,1,3,3], ���� 2��
* ���ͣ�
* 2 ֻ������һ�Ρ�
*/
class Solution {
public:
	/**
	* @param nums: The number array
	* @return: Return the single number
	*/
	int getSingleNumber(vector<int> &nums) {
		// Write your code here
		int left = 0, right = nums.size() - 1;
		while (left<right)
		{
			int middle = (left + right) / 2;
			if (nums[middle] == nums[middle - 1])
			{
				//���м�λ�õ�����������������,������ż�Խ����ж�
				//�м�λ��ǰ��ż������,��Ŀ�����ֳ������м�λ���ұ�,������������
				if ((middle - left) % 2 == 0)
				{
					right = middle - 2;
				}
				else
				{
					left = middle + 1;
				}
			}
			else if (nums[middle] == nums[middle + 1])
			{
				//���м�λ�õ�������ǰ��������,������ż�Խ����ж�
				//�м�λ��ǰ��ż������,��Ŀ�����ֳ������м�λ�����,����������ұ�
				if ((middle - left) % 2 == 0)
				{
					left = middle + 2;
				}
				else
				{
					right = middle - 1;
				}
			}
			else
			{
				//ֱ���ҵ�Ŀ������
				return nums[middle];
			}
		}
		return nums[left];
	}
};
#endif