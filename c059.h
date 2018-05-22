#ifndef C59_H
#define C59_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ��ӽ�������֮��
*
* ����
* ��һ������ n ������������ S, �ҵ������������ target ��ӽ�����Ԫ�飬�������������ĺ͡�
* ֻ��Ҫ������Ԫ��֮�ͣ����践����Ԫ�鱾��
* ����
* ���� S = [-1, 2, 1, -4] and target = 1. ����ӽ� 1 ����Ԫ���� -1 + 2 + 1 = 2.
* ��ս
* O(n^2) ʱ��, O(1) ����ռ䡣
*/
class Solution {
public:
	int threeSumClosest(vector<int> nums, int target) {
		// write your code here
		if (nums.empty()|| nums.size()<3)
			return 0;
		int len = nums.size();
		int res = nums[0]+nums[1]+nums[len-1];
		//ֻѰ����Ԫ�鲻�ؿ���˳��
		sort(nums.begin(), nums.end());
		//��sum����target,k��ǰ�ƶ�,sumֵ��С
		//��sumС��target,j����ƶ�,sumֵ���
		for (int i = 0; i < len - 2; ++i)
		{
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				res = absVal(res - target)<absVal(sum - target) ? res : sum;
				if (sum>target)
					--k;
				else if (sum == target)
					return target;
				else
					++j;
			}
		}
		return res;
	}
	int absVal(int a)
	{
		if (a >= 0)
			return a;
		else
			return -a;
	}
};
#endif