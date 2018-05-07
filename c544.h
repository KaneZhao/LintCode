#ifndef C544_H
#define C544_H
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
/*
* ǰK����
*
* ��һ���������ҵ�ǰK�����
* ����
* ���� [3,10,1000,-99,4,100], k = 3.
* ���� [1000, 100, 10]
*/
class Solution {
public:
	/**
	* @param nums: an integer array
	* @param k: An integer
	* @return: the top k largest numbers in array
	*/
	vector<int> topk(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty())
			return nums;
		//�淶��k��ֵ
		if (k > nums.size())
			k = nums.size();
		priority_queue<int,vector<int>,greater<int>> que;//������С��
		vector<int> res;
		//��que�Ĵ�СС��k,ֱ�����Ԫ��c
		//����,�Ƚ�c����С�ѶѶ�ֵ�Ĵ�С,���c�ϴ�,�����Ѷ�Ԫ��,���Ԫ��c
		for (auto c : nums)
		{
			if (que.size() < k)
				que.push(c);
			else
			{
				if (c>que.top())
				{
					que.pop();
					que.push(c);
				}
			}
		}
		//���Ѷ�Ԫ�����β���res��ͷ��
		while (!que.empty())
		{
			res.insert(res.begin(),que.top());
			que.pop();
		}
		return res;
	}
};
#endif