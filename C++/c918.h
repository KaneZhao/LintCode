#ifndef C918_H
#define C918_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ����֮��
*
* ����
* ����һ��n�������������һ��Ŀ������target���ҵ��±�Ϊi��j��k������Ԫ��0 <= i < j < k < n����������nums[i] + nums[j] + nums[k] < target.
* ����
* ���� nums = [-2,0,1,3], target = 2, ���� 2.
* ����:
* ��Ϊ����������Ԫ��֮�ͣ����ǵĺ�С��2:
* [-2, 0, 1]
* [-2, 0, 3]
* ��ս
* Could you solve it in O(n2) runtime?
*/
class Solution {
public:
	/**
	* @param nums:  an array of n integers
	* @param target: a target
	* @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
	*/
	int threeSumSmaller(vector<int> &nums, int target) {
		// Write your code here
		if (nums.empty()||nums.size()<3)
			return 0;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		int cnt = 0;
		for (int i = 0; i < len - 2; ++i)
		{
			int j = i + 1;
			int k = len - 1;
			while (j<k)
			{
				if (nums[i] + nums[j] + nums[k] < target)
				{
					cnt += k - j;
					++j;
				}
				else
					--k;
			}
		}
		return cnt;
	}
};
#endif