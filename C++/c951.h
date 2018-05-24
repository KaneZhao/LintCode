#ifndef C951_H
#define C951_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ����
*
* ��һ������Ҫ�����ţ���������ż��λ�ϵ�����С����������λ�ϵ�����ͬʱ��ż��λ�ϵ���Ҳ����������������λ�ϵ�Ҳ������������
* ע������
* ���鳤��Ϊn��n <= 100000��
* �����±��0��ʼ��
* ����
* ����array = [-1,0,1,-1,5,10], ���� [-1,1,-1,5,0,10]��
* ���ͣ�
* [[-1,1,-1,5,0,10]����������
* ����array = [2,0,1,-1,5,10], ���� [-1,2,0,5,1,10]��
* ���ͣ�
* [-1,2,0,5,1,10]����������
*/
class Solution {
public:
	/**
	* @param nums: the num arrays
	* @return: the num arrays after rearranging
	*/
	vector<int> rearrange(vector<int> &nums) {
		// Write your code here 
		if (nums.empty())
			return nums;
		sort(nums.begin(), nums.end());
		//����С��������ż��λ��,�ϴ�������������λ��
		int i = 1, j = nums.size() % 2 == 0 ? nums.size() - 2 : nums.size() - 1;
		while (i<j)
		{
			swap(nums[i], nums[j]);
			i += 2;
			j -= 2;
		}
		//�����������λ�ú�ż��λ�÷ֱ��������
		quickSort(nums, 0, nums.size() % 2 == 0 ? nums.size() - 2 : nums.size() - 1);
		quickSort(nums, 1, nums.size() % 2 == 0 ? nums.size() - 1 : nums.size() - 2);
		return nums;
	}
	//�������и�һ��Ԫ�ؽ��п���
	void quickSort(vector<int> &nums, int left, int right)
	{
		if (left > right)
			return;
		int i = left, j = right, temp = nums[left];
		while (i < j)
		{
			while (i < j&&nums[j] >= temp)
				j -= 2;
			while (i < j&&nums[i] <= temp)
				i += 2;
			if (i < j)
			{
				nums[i] ^= nums[j];
				nums[j] ^= nums[i];
				nums[i] ^= nums[j];
			}
		}
		nums[left] = nums[i];
		nums[i] = temp;
		quickSort(nums, left, i - 2);
		quickSort(nums, i + 2, right);
	}
};
#endif