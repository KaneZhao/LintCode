#ifndef C005_H
#define C005_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��k��Ԫ��
*
* ���������ҵ���k���Ԫ��
* ����Խ��������е�Ԫ�ص�λ��
* ����
* �������� [9,3,2,4,8]���������Ԫ���� 4
* �������� [1,2,3,4,5]����һ���Ԫ���� 5���ڶ����Ԫ���� 4���������Ԫ���� 3���Դ�����
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
*/
class Solution {
public:
	/*
	* @param n: An integer
	* @param nums: An array
	* @return: the Kth largest element
	*/
	int kthLargestElement(int n, vector<int> &nums) {
		// write your code here
		if (nums.empty() || n <= 0)
			return 0;
		int min = INT_MAX;
		for (auto c : nums)
		{
			if (c < min)
				min = c;
		}
		//��n>=lenʱ,��n���Ԫ��Ϊnums����СԪ��
		int len = nums.size();
		if (n >= len)
			return min;
		int left = 0, right = nums.size() - 1;
		int pos = quickSort(nums, left, right);
		//��n��Ԫ��Ҳ����nums�����ĵ�len-n+1��Ԫ��
		//���ö��ַ����k+1��Ԫ��
		int k = len - n;
		while (pos != k)
		{
			if (pos > k)
			{
				right = pos - 1;
				pos = quickSort(nums, left, right);
			}
			else
			{
				left = pos + 1;
				pos = quickSort(nums, left, right);
			}
		}
		return nums[k];
	}
	//������������[left,right]���п���,������nums[left]������λ��
	int quickSort(vector<int> &nums, int left, int right)
	{
		int temp = nums[left];
		int i = left, j = right;
		while (i < j)
		{
			while ( i < j && nums[j]>= temp)
				--j;
			while ( i < j && nums[i] <= temp)
				++i;
			if (i < j)
				swap(nums[i], nums[j]);
		}
		nums[left] = nums[i];
		nums[i] = temp;
		return i;
	}
};
#endif