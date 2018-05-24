#ifndef C793_H
#define C793_H
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
* Intersection of Arrays
*
* 给出多个数组，求它们的交集。输出他们交集的大小。
* 注意事项
* 输入的所有数组元素总数不超过500000。
* 题目数据每个数组里的元素没有重复。
* 样例
* 给出 [[1,2,3],[3,4,5],[3,9,10]]，返回 1。
* 解释：
* 只有元素3在所有的数组中出现过。交集为[3]，大小为1。
* 给出 [[1,2,3,4],[1,2,5,6,7],[9,10,1,5,2,3]]，返回2。
* 解释：
* 只有元素1,2均在所有的数组出现过。交集为[1,2]，大小为2。
*/
class Solution {
public:
	/**
	* @param arrs: the arrays
	* @return: the number of the intersection of the arrays
	*/
	int intersectionOfArrays(vector<vector<int>> &arrs) {
		// write your code here
		if (arrs.empty()||arrs[0].empty())
			return 0;
		int size = arrs.size();
		if (size == 1)
			return arrs[0].size();
		set<int> set1,set2;
		for (auto c : arrs[0])
			set1.insert(c);
		for (int i = 1; i < size; ++i)
		{
			set2.clear();
			for (auto t : arrs[i])
			{
				if (set1.find(t) != set1.end())
					set2.insert(t);
			}
			set1 = set2;
		}
		return set1.size();
	}
};
#endif