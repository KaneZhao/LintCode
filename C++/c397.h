#ifndef C397_H
#define C397_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最长上升连续子序列
*
* 给定一个整数数组（下标从 0 到 n-1， n 表示整个数组的规模），请找出该数组中的最长上升连续子序列。（最长上升连续子序列可以定义为从右到左或从左到右的序列。）
* 注意事项
* O(n) time and O(1) extra space.
* 您在真实的面试中是否遇到过这个题？ Yes
* 样例
* 给定 [5, 4, 2, 1, 3], 其最长上升连续子序列（LICS）为 [5, 4, 2, 1], 返回 4.
* 给定 [5, 1, 2, 3, 4], 其最长上升连续子序列（LICS）为 [1, 2, 3, 4], 返回 4.
*/
class Solution {
public:
	/*
	* @param A: An array of Integer
	* @return: an integer
	*/
	int longestIncreasingContinuousSubsequence(vector<int> &A) {
		// write your code here
		if (A.empty())
			return 0;
		int len = A.size();
		if (len == 1)
			return 1;
		int len1 = 1, len2 = 1;
		int res1 = 1, res2 = 1;
		//分别求出最长递增连续子序列和最长递减连续子序列,返回长度的最大值
		for (int i = 0; i < len - 1; ++i)
		{
			if (A[i]>A[i + 1])
				len1++;
			else
			{
				res1 = maxVal(res1, len1);
				len1 = 1;
			}
		}
		res1 = maxVal(res1, len1);
		for (int i = 0; i < len - 1; ++i)
		{
			if (A[i]<A[i + 1])
				len2++;
			else
			{
				res2 = maxVal(res2, len2);
				len2 = 1;
			}
		}
		res2 = maxVal(res2, len2);
		return maxVal(res1, res2);
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif