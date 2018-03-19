#ifndef C125_H
#define C125_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �������� II
*
* ����n����Ʒ�����A[i]�����ֵV[i]��������װ��һ����СΪm�ı����������װ����ܼ�ֵ�ж��
* ע������
* A[i], V[i], n, m��Ϊ�������㲻�ܽ���Ʒ�����з֡�������ѡ����Ʒ�������ҪС�ڵ��ڸ�����m��
* ����
* ������Ʒ���[2, 3, 5, 7]�Ͷ�Ӧ�ļ�ֵ[1, 5, 2, 4], ���豳����СΪ10�Ļ�������ܹ�װ��ļ�ֵΪ9��
* ��ս
* O(n x m) memory is acceptable, can you do it in O(m) memory?
*/
class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A & V: Given n items with size A[i] and value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> A, vector<int> V) {
		// write your code here
		if (A.empty() || V.empty())
			return 0;
		vector<int> dp(m + 1, 0);//dp[j]��ʾ����Ϊjʱ���Դ�ŵ�����ֵ
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = m; j >= A[i]; --j)
			{
				dp[j] = maxVal(dp[j - A[i]] + V[i], dp[j]);//����������A[i],�ճ�A[i]���,������Ӧ�ļ�ֵV[i]����ԭdp[j]�Ƚ�
			}
		}
		return dp[m];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif