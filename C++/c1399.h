#ifndef C1399_H
#define C1399_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��Ӳ��
*
* ����
* ��n��Ӳ���ų�һ�ţ�ÿ��Ҫ�������߻������Ҳ��ó�һ��Ӳ�ҡ��ܹ���k�Σ�дһ���㷨��ʹ���õ���Ӳ�ҵĺ����
* 1 <= k <= n <= 100000��
* Ӳ�ҵļ�ֵ������10000��
* ����
* ���� list = [5,4,3,2,1], k = 2, ���� 9.
* ���ͣ�
* ����߿�ʼ��ȡ����Ӳ�Ҽ��ɡ�
* ���� list = [5,4,3,2,1,6], k = 3, ���� 15.
* ����߿�ʼ��ȡ����Ӳ��,�ұ�ȡһ�����ɡ�
*/
class Solution {
public:
	/**
	* @param list: The coins
	* @param k: The k
	* @return: The answer
	*/
	int takeCoins(vector<int> &list, int k) {
		// Write your code here
		int len = list.size();
		//list[i]��ʾ��0��list[i]Ԫ���ۼӵ�ֵ
		for (int i = 1; i < len; ++i)
			list[i] += list[i - 1];
		int res = INT_MIN;
		//ȡk��,��������ȡ�Ĵ�������Ϊ0,k;1,k-1;2,k-2...
		//������Һ͵����ֵ
		for (int i = 0; i <= k; ++i)
		{
			int left = 0, right = 0;
			if (i>0)
				left = list[i - 1];
			if (i<k)
				right = list[len - 1] - list[len - 1 - k + i];
			res = maxVal(res, left + right);
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif