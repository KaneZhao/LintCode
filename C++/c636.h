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
		int mid = INT_MIN;//表示中间值ak
		stack<int> stack;//存放所有大于mid的元素
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i] < mid)//如果当前元素小于mid,找到ai
				return true;
			else
			{
				//若当前元素大于栈顶元素,则将栈顶元素赋值给mid,再将此元素压栈
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