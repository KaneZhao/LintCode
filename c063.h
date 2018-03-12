#ifndef C63_H
#define C63_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 搜索旋转排序数组 II
* 跟进“搜索旋转排序数组”，假如有重复元素又将如何？
* 是否会影响运行时间复杂度？
* 如何影响？
* 为何会影响？
* 写出一个函数判断给定的目标值是否出现在数组中。
* 样例
* 给出[3,4,4,5,7,0,1,2]和target=4，返回 true
*/
class Solution {
public:
	/**
	* @param A: an integer ratated sorted array and duplicates are allowed
	* @param target: An integer
	* @return: a boolean
	*/
	bool search(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
			return false;
		int minPos = findMin(A);
		//在两个递增子序列中查找
		bool n1 = findNum(A, 0, minPos - 1, target);
		bool n2 = findNum(A, minPos, A.size() - 1, target);
		return n1 || n2;
	}
	//二分查找
	bool findNum(vector<int> &A, int i, int j, int target)
	{
		if (i > j)
			return false;
		if (i == j)
			return A[i] == target;
		int l = i, r = j;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (A[mid] > target)
				r = mid - 1;
			else if (A[mid] == target)
				return true;
			else
				l = mid + 1;
		}
		return false;
	}
	//找到两个递增子数组的分界点
	int findMin(vector<int> &A)
	{
		int l = 0, r = A.size() - 1;
		int mid = l;
		while (A[l] >= A[r])
		{
			if (r - l == 1)
			{
				mid = r;
				break;
			}
			int mid = (l + r) / 2;
			//解决存在重复的数字的问题
			//出现这种情况只能顺序查找
			if (A[mid] == A[l] && A[mid] == A[r])
				return MinInOrder(A, l, r);
			if (A[mid] >= A[l])
				l = mid;
			else if (A[mid] <= A[r])
				r = mid;
		}
		return mid;
	}
	int MinInOrder(vector<int> &A, int i, int j)
	{
		int res = i;
		for (int k = i + 1; k <= j; ++k)
		{
			if (A[res] > A[k])
				res = k;
		}
		return res;
	}
};
#endif