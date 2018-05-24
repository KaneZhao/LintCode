#ifndef C636_H
#define C636_H
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	/*
	* @param nums: a list of n integers
	* @return: true if there is a 132 pattern or false
	*/
	bool find132pattern(vector<int> &nums) {
		// write your code here
		int len = nums.size();
		int mid = INT_MIN;//��ʾ�м�ֵak
		stack<int> stack;//������д���mid��Ԫ��
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i] < mid)//�����ǰԪ��С��mid,�ҵ�ai
				return true;
			else
			{
				//����ǰԪ�ش���ջ��Ԫ��,��ջ��Ԫ�ظ�ֵ��mid,�ٽ���Ԫ��ѹջ
				while (!stack.empty() && nums[i]>stack.top())
				{
					mid = stack.top();
					stack.pop();
				}
				stack.push(nums[i]);
			}
		}
		return false;
	}
};
#endif