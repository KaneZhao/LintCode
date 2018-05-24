#ifndef C911_H
#define C911_H
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
* ���������֮��Ϊk
*
* ��һ������nums��Ŀ��ֵk���ҵ���������������飬ʹ���е�Ԫ�غ�Ϊk�����û�У��򷵻�0��
* ע������
* ����֮�ͱ�֤��32λ�з����������ķ�Χ��
* ����
* �������� nums = [1, -1, 5, -2, 3]��k = 3������4
* ������
* ������[1, -1, 5, -2]�ĺ�Ϊ3���ҳ������
* ��������nums = [-2, -1, 2, 1]�� k = 1������2
* ������
* ������[-1, 2]�ĺ�Ϊ1���ҳ������
* ��ս
* �ܷ���O(n)��ʱ�临�Ӷ���ɣ�
*/
class Solution {
public:
	/**
	* @param nums: an array
	* @param k: a target value
	* @return: the maximum length of a subarray that sums to k
	*/
	int maxSubArrayLen(vector<int> &nums, int k) {
		// Write your code here
		if (nums.empty())
			return 0;
		int res = 0;
		unordered_map<int, int> m;//���nums��Ԫ�ص�ֵ��λ��
		int len = nums.size();
		//nums[i]��ʾ��nums[0]��nums[i]�ĺ�
		for (int i = 1; i < len; ++i)
			nums[i] += nums[i - 1];
		for (int i = 0; i < len; ++i)
		{
			//�ظ�Ԫ��,��Ž�Сλ��
			if (m.find(nums[i]) == m.end())
				m[nums[i]] = i;
		}
		//��nums[i]����k,������Ϊnums[0]��nums[i],����Ϊi + 1
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i] == k)
			{
				res = i + 1;
				break;
			}
		}
		//��m��Ѱ��nums[i]-k,�������,��m[nums[i]-k]��ֵС�ڵ���i
		//˵����nums[0]��nums[i]��,����������ĺ�λk,�����鳤��Ϊi - m[nums[i] - k
		for (int i = 0; i < len; ++i)
		{
			if (m.find(nums[i] - k) != m.end() && m[nums[i] - k] <= i)
			{
				res = maxVal(res, i - m[nums[i] - k]);
			}
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif