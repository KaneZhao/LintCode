#ifndef C1210_H
#define C1210_H
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
* Increasing Subsequences
*
* Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
* ע������
* 1.The length of the given array will not exceed 15.
* 2.The range of integer in the given array is [-100,100].
* 3.The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
* ����
* Input: [4, 6, 7, 7]
* Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
*/
class Solution {
public:
	/**
	* @param nums: an integer array
	* @return: all the different possible increasing subsequences of the given array
	*/
	vector<vector<int>> findSubsequences(vector<int> &nums) {
		// Write your code here
		vector<vector<int>> res;
		if (nums.empty() || nums.size() == 1)
			return res;
		int len = nums.size();
		vector<set<vector<int>>> v(len);//v[i]�����nums[i]��β�����е���������
		for (int i = 1; i < len; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				//����i,��j=i-1��ʼ��ǰѰ��nums[j]<=nums[i]
				//���nums[j]С��nums[i],���Խ�{nums[j],nums[i]}��ӵ�v[i]
				//����v[j]�е������鶼���nums[j],֮����ӵ�v[i]��
				//��nums[j]����nums[i],������ǰѰ�ұ����ظ�
				if (nums[j] <= nums[i])
				{
				    v[i].insert({ nums[j], nums[i] });
					for (auto c : v[j])
					{
						vector<int> temp = c;
						temp.push_back(nums[i]);
						v[i].insert(temp);
					}
					if (nums[j] == nums[i])
					{
						break;
					}
				}
			}
		}
		for (auto c : v)
		{
			for (auto t : c)
			{
				res.push_back(t);
			}
		}
		return res;
	}
};
#endif