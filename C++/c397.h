#ifndef C397_H
#define C397_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ���������������
*
* ����һ���������飨�±�� 0 �� n-1�� n ��ʾ��������Ĺ�ģ�������ҳ��������е���������������С�����������������п��Զ���Ϊ���ҵ��������ҵ����С���
* ע������
* O(n) time and O(1) extra space.
* ������ʵ���������Ƿ�����������⣿ Yes
* ����
* ���� [5, 4, 2, 1, 3], ����������������У�LICS��Ϊ [5, 4, 2, 1], ���� 4.
* ���� [5, 1, 2, 3, 4], ����������������У�LICS��Ϊ [1, 2, 3, 4], ���� 4.
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
		//�ֱ������������������к���ݼ�����������,���س��ȵ����ֵ
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