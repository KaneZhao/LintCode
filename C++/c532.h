#ifndef C532_H
#define C532_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 逆序对
*
* 描述
* 在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。给你一个数组，求出这个数组中逆序对的总数。
* 概括：如果a[i] > a[j] 且 i < j， a[i] 和 a[j] 构成一个逆序对。
* 样例
* 序列 [2, 4, 1, 3, 5] 中，有 3 个逆序对 (2, 1), (4, 1), (4, 3)，则返回 3 。
*/
class Solution {
public:
	/*
	* @param A: an array
	* @return: total of reverse pairs
	*/
	long long reversePairs(vector<int> &A) {
		// write your code here
		if (A.empty())
			return 0;
		int len = A.size(); 
		long long cnt = 0;
		vector<int> vec;
		vec.push_back(A.back());
		for (int i = len - 2; i >= 0; --i)
		{
			int pos = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin();
			vec.insert(vec.begin() + pos, A[i]);
			cnt += pos;
		}
		return cnt;
	}
};
#endif