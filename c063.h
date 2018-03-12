#ifndef C63_H
#define C63_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ������ת�������� II
* ������������ת�������顱���������ظ�Ԫ���ֽ���Σ�
* �Ƿ��Ӱ������ʱ�临�Ӷȣ�
* ���Ӱ�죿
* Ϊ�λ�Ӱ�죿
* д��һ�������жϸ�����Ŀ��ֵ�Ƿ�����������С�
* ����
* ����[3,4,4,5,7,0,1,2]��target=4������ true
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
		//�����������������в���
		bool n1 = findNum(A, 0, minPos - 1, target);
		bool n2 = findNum(A, minPos, A.size() - 1, target);
		return n1 || n2;
	}
	//���ֲ���
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
	//�ҵ���������������ķֽ��
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
			//��������ظ������ֵ�����
			//�����������ֻ��˳�����
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