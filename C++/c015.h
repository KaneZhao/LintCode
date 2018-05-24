#ifndef C15_H
#define C15_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ȫ����
*
* ����һ�������б����������п��ܵ����С�
* ע������
* ����Լ���û���ظ����֡�
* ����
* ����һ���б�[1,2,3]����ȫ����Ϊ��
* [
* [1,2,3],
* [1,3,2],
* [2,1,3],
* [2,3,1],
* [3,1,2],
* [3,2,1]
* ]
*/
class Solution {
public:
	/*
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> &nums) {
		// write your code here
		vector<vector<int>> res;
		if (nums.empty())
			return{ {} };
		//�Ƚ�nums��Ϊֵ��С������
		sort(nums.begin(), nums.end());
		res.push_back(nums);
		int pos = 0;
		//��nums���ǵݼ�����ʱ
		//�Ӻ���ǰѰ�ҵ�һ������nums[pos]��λ��temp,����nums[pos]��nums[temp]
		//֮��nums[pos+1]���Ժ����������
		while (hasNext(nums, pos))
		{
			int val = nums[pos];
			int temp = 0;
			for (int i = nums.size() - 1; i >= 0; --i)
			{
				if (nums[i] > val)
				{
					temp = i;
					break;
				}
			}
			swap(nums[pos], nums[temp]);
			reverse(nums.begin() + pos + 1, nums.end());
			res.push_back(nums);
		}
		return res;
	}
	//�ж������Ƿ��ǵݼ�
	//����ǵݼ�����,������û����һ�������������,����false
	//����,�Ӻ���ǰѰ�ҵ�һ��nums[i-1]<nums[i]��λ��,����λ��i - 1��ֵ��pos
	bool hasNext(vector<int> &nums,int &pos)
	{
		int i = nums.size() - 1;
		while (i > 0)
		{
			if (nums[i] > nums[i - 1])
			{
				pos = i - 1;
				return true;
			}
			--i;
		}
		return false;
	}
};
class Solution2 {
public:
	/*
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return{ {} };
		helper(nums, 0);
		return res;
	}
	void helper(vector<int> &nums, int start)
	{
		if (start == nums.size())
		{
			res.push_back(nums);
		}
		for (int i = start; i < nums.size(); ++i)
		{
			swap(nums[start], nums[i]);
			helper(nums, start + 1);
			swap(nums[start], nums[i]);
		}
	}
	vector<vector<int>> res;
};
#endif
