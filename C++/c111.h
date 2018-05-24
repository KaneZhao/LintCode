#ifndef C111_H
#define C111_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��¥��
*
* ������������¥�ݣ���Ҫn������ܵ��ﶥ������ÿ����ֻ����һ�����������������ж����ֲ�ͬ�ķ�������¥������
* ����
* ����n=3��1+1+1=1+2=2+1=3������3�ֲ�ͬ�ķ���
* ���� 3
*/
class Solution {
public:
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int climbStairs(int n) {
		// write your code here
		if (n == 0)
			return 1;
		vector<int> v(n);
		v[0] = 1;
		v[1] = 2;
		//����ÿ��ֻ����һ����������
		//����i��,�����Ǵ�i-1����i-2�߳�����
		for (int i = 2; i <= n - 1; ++i)
		{
			v[i] = v[i - 1] + v[i - 2];
		}
		return v[n - 1];
	}
};
#endif