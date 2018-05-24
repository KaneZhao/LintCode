#ifndef C62_H
#define C62_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ������ת��������
*
* ������һ������İ�δ֪����ת����ת������(���磬0 1 2 4 5 6 7 ���ܳ�Ϊ4 5 6 7 0 1 2)������һ��Ŀ��ֵ����������������������ҵ�Ŀ��ֵ���������е�����λ�ã����򷵻�-1��
* ����Լ��������в������ظ���Ԫ�ء�
* ����
* ����[4, 5, 1, 2, 3]��target=1������ 2
* ����[4, 5, 1, 2, 3]��target=0������ -1
* ��ս
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
		//�ֱ��������������
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
	//�����������������������鹹�ɵ�
	//�ҵ���ֽ��,Ҳ������Сֵ���ڵ�λ��
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
	//���ַ�����
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