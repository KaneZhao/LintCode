#ifndef C163_H
#define C163_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��ͬ�Ķ��������
*
* ���� n������ 1...n Ϊ�ڵ���ɵĲ�ͬ�Ķ���������ж����֣�
* ����
* ����n = 3����5�ֲ�ͬ��̬�Ķ����������
* 1           3    3       2      1
*  \         /    /       / \      \
*   3      2     1       1   3      2
*  /      /       \                  \
* 2      1         2                  3
*/
class Solution {
public:
	/**
	* @paramn n: An integer
	* @return: An integer
	*/
	int numTrees(int n) {
		// write your code here
		if (n < 0)
			return 0;
		/*��f(n)����ʾ���������������࣬�׵�f(0)=0(�߽�����)��f(1)=1��f(2)=2�� 
		����f(3)�������������
		��1Ϊ����2��3��1����������Ϊf(2);
		��2Ϊ����1��3�ֱ�Ϊ����������Ϊf(1);
		��3Ϊ����1��2��3����������Ϊf(2)��
		f(3) = f(2) + f(1) + f(2)
		��f(i)=f(k-1)*f(i-k)
		*/
		vector<int> v(n + 1);
		v[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int k = 1; k <= i; ++k)
			{
				v[i] += v[k - 1] * v[i - k];
			}
		}
		return v[n];
	}
};
#endif