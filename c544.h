#ifndef C544_H
#define C544_H
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
/*
* 前K大数
*
* 在一个数组中找到前K大的数
* 样例
* 给出 [3,10,1000,-99,4,100], k = 3.
* 返回 [1000, 100, 10]
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
		//规范化k的值
		if (k > nums.size())
			k = nums.size();
		priority_queue<int,vector<int>,greater<int>> que;//构建最小堆
		vector<int> res;
		//当que的大小小于k,直接添加元素c
		//否则,比较c与最小堆堆顶值的大小,如果c较大,弹出堆顶元素,添加元素c
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
		//将堆顶元素依次插入res的头部
		while (!que.empty())
		{
			res.insert(res.begin(),que.top());
			que.pop();
		}
		return res;
	}
};
#endif