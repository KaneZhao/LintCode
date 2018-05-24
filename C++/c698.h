#ifndef C698_H
#define C698_H
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<utility>
using namespace std;
/*
* 数组中最大的差值
* 给 m 个数组, 每一个数组均为升序. 现在你可以从两个不同的数组中挑选两个整数(每一个数组选一个)并且计算差值. 我们将两个整数 a 和 b 之间的差定义为它们的绝对差 |a - b|. 你的任务是去找到最大的差值.
*
* 注意事项
* 每一个给出的数组长度至少为 1. 至少有两个不为空的数组
* m 个数组中所有整数的个数和在 [2, 10000]范围内.
* m 个数组中所有的整数均将在[-10000, 10000]范围内.
*
* 样例
* 给一个数组 [[1,2,3], [4,5], [1,2,3]], 返回 4
* 获得最大差值的一种方式是在第一个数组或第三个数组中取 1, 在第二个数组中取 5.
*/
class Solution {
public:
	/*
	* @param : an array of arrays
	* @return: return the max distance among arrays
	*/
	int maxDiff(vector<vector<int>> &arrs) {
		// write your code here
		priority_queue<pair<int, int>> queMax;//维护最大堆
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > queMin;//维护最小堆
		//堆中存放(元素值,其所在数组的编号)
		for (int i = 0; i < arrs.size();++i)
		{
			if (!arrs[i].empty())
			{
				queMax.push(make_pair(arrs[i].back(), i));
				queMin.push(make_pair(arrs[i][0], i));
			}
		}
		//若堆顶的序号不同，直接返回差值。否则，计算最大堆中的最大值和最小堆中第二小的值之差，以及
		//最小堆的最小值与最大堆中第二大值得差，并取二者最大值
		if (queMax.top().second != queMin.top().second)
		{
			return queMax.top().first - queMin.top().first;
		}
		else
		{
			int maxVal = queMax.top().first;
			queMax.pop();
			int minVal = queMin.top().first;
			queMin.pop();
			return Max(maxVal - queMin.top().first, queMax.top().first - minVal);
		}
	}
	int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif