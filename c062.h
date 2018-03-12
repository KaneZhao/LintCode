#ifndef C62_H
#define C62_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 搜索旋转排序数组
*
* 假设有一个排序的按未知的旋转轴旋转的数组(比如，0 1 2 4 5 6 7 可能成为4 5 6 7 0 1 2)。给定一个目标值进行搜索，如果在数组中找到目标值返回数组中的索引位置，否则返回-1。
* 你可以假设数组中不存在重复的元素。
* 样例
* 给出[4, 5, 1, 2, 3]和target=1，返回 2
* 给出[4, 5, 1, 2, 3]和target=0，返回 -1
* 挑战
* O(logN) time
*/
class Solution {
public:
	/**
	* @param A: an integer rotated sorted array
	* @param target: an integer to be searched
	* @return: an integer
	*/
	int search(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
			return -1;
		if (A.size() == 1)
			return A[0] == target?0:-1;
		//分别查找两个子序列
		int minPos = findMin(A);
		if (minPos != 0)
		{
			int res1 = findNum(A, 0, minPos - 1, target);
			if (res1 != -1)
				return res1;
		}	
		int res2 = findNum(A, minPos, A.size() - 1, target);
		if (res2 != -1)
			return res2;
		return -1;
	}
	//数组是由两个递增的子数组构成的
	//找到其分界点,也就是最小值所在的位置
	int findMin(vector<int> &A)
	{
		int l = 0, r = A.size() - 1;
		int mid = l;
		while (A[l] >= A[r])
		{
			if (l == r - 1)
			{
				mid = r;
				break;
			}
			mid = (l + r) / 2;
			if (A[mid] >= A[l])
				l = mid;
			else if (A[mid] <= A[r])
				r = mid;
		}
		return mid;
	}
	//二分法查找
	int findNum(vector<int> &A, int i, int j, int target)
	{
		int l = i,r = j;
		int mid = 0;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (A[mid]>target)
				r = mid - 1;
			else if (A[mid] == target)
				return mid;
			else
				l = mid + 1;
		}
		return -1;
	}
};
#endif