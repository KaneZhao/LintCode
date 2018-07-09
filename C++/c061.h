#ifndef C61_H
#define C61_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��������
*
* ����
* ����һ������ n ���������������飬�ҳ�����Ŀ��ֵ target ����ʼ�ͽ���λ�á�
* ���Ŀ��ֵ���������У��򷵻�[-1, -1]
* ����
* ����[5, 7, 7, 8, 8, 10]��Ŀ��ֵtarget=8,
* ����[3, 4]
* ��ս
* ʱ�临�Ӷ� O(log n)
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
		//Ѱ�������target
		//��mid����left ���� midǰһ��Ԫ�ز�Ϊtarget, mid��������ߵ�target
		//���midǰһ��Ԫ��������target,�Ͱ�right��Ϊmid - 1
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
		//Ѱ�����ұߵ�target
		//��mid����right ���� mid�ĺ�һ��Ԫ�ز�Ϊtarget, mid�������ұߵ�target
		//���mid�ĺ�һ��Ԫ����Ϊtarget, ��left��Ϊmid + 1
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