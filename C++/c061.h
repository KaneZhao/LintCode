#ifndef C61_H
#define C61_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 搜索区间
*
* 描述
* 给定一个包含 n 个整数的排序数组，找出给定目标值 target 的起始和结束位置。
* 如果目标值不在数组中，则返回[-1, -1]
* 样例
* 给出[5, 7, 7, 8, 8, 10]和目标值target=8,
* 返回[3, 4]
* 挑战
* 时间复杂度 O(log n)
*/
class Solution {
public:
	/**
	* @param A: an integer sorted array
	* @param target: an integer to be inserted
	* @return: a list of length 2, [index1, index2]
	*/
	vector<int> searchRange(vector<int> &A, int target) {
		// write your code here
		vector<int> res{ -1, -1 };
		if (A.empty())
			return res;
		int left = 0, right = A.size() - 1;
		int mid = 0;
		//寻找最左边target
		//当mid等于left 或者 mid前一个元素不为target, mid就是最左边的target
		//如果mid前一个元素依旧是target,就把right置为mid - 1
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (A[mid]>target)
				right = mid - 1;
			else if (A[mid] < target)
				left = mid + 1;
			else
			{
				if (mid == left || A[mid - 1] != target)
				{
					res[0] = mid;
					break;
				}
				else if (A[mid - 1] == target)
				{
					right = mid - 1;
				}
			}
		}
		left = 0, right = A.size() - 1;
		//寻找最右边的target
		//当mid等于right 或者 mid的后一个元素不为target, mid就是最右边的target
		//如果mid的后一个元素认为target, 把left置为mid + 1
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (A[mid]>target)
				right = mid - 1;
			else if (A[mid] < target)
				left = mid + 1;
			else
			{
				if (mid == right || A[mid + 1] != target)
				{
					res[1] = mid;
					break;
				}
				else if (A[mid + 1] == target)
				{
					left = mid + 1;
				}
			}
		}
		return res;
	}
};
#endif