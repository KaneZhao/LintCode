#ifndef C45_H
#define C45_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ����������
*
* ����
* ����һ���������飬�ҳ��������ص���������A��B��ʹ����������͵Ĳ�ľ���ֵ|SUM(A) - SUM(B)|���
* ����������Ĳ�ֵ��
* ���������ٰ���һ����
* ����
* ��������[1, 2, -3, 1]������ 6
* ��ս
* ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)
*/
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer indicate the value of maximum difference between two substrings
	*/
	int maxDiffSubArrays(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return 0;
		int len = nums.size();
		//ForMax[i]��ʾ��nums[0]��nums[i]��������͵����ֵ
		//ForMin[i]��ʾ��nums[0]��nums[i]��������͵���Сֵ
		//RevMax[i]��ʾ��nums[i]��nums[len-1]��������͵����ֵ
		//RevMin[i]��ʾ��nums[i]��nums[len-1]��������͵���Сֵ
		vector<int> ForMax(len), ForMin(len), RevMax(len), RevMin(len);
		ForMax[0] = nums[0];
		ForMin[0] = nums[0];
		RevMax[len - 1] = nums[len - 1];
		RevMin[len - 1] = nums[len - 1];
		int res = INT_MIN;
		int Max = nums[0], Min = nums[0];
		int curMax = nums[0], curMin = nums[0];
		for (int i = 1; i < len; ++i)
		{
			if (curMax>0)
				curMax += nums[i];
			else
				curMax = nums[i];
			if (curMax > Max)
				Max = curMax;
			ForMax[i] = Max;
			if (curMin < 0)
				curMin += nums[i];
			else
				curMin = nums[i];
			if (curMin < Min)
				Min = curMin;
			ForMin[i] = Min;
		}
		Max = nums.back(), Min = nums.back();
		curMax = Max, curMin = Min;
		for (int i = len - 2; i >= 0; --i)
		{
			if (curMax>0)
				curMax += nums[i];
			else
				curMax = nums[i];
			if (curMax > Max)
				Max = curMax;
			RevMax[i] = Max;
			if (curMin < 0)
				curMin += nums[i];
			else
				curMin = nums[i];
			if (curMin < Min)
				Min = curMin;
			RevMin[i] = Min;
		}
		//����ForMax[i] - RevMin[i + 1]
		for (int i = 0; i < len - 1; ++i)
		{
			res = max(res, ForMax[i] - RevMin[i + 1]);
		}
		//����RevMax[i] - ForMin[i - 1]
		for (int i = len - 1; i > 0; --i)
		{
			res = max(res, RevMax[i] - ForMin[i - 1]);
		}
		return res;
	}
};

#endif