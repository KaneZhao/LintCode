#ifndef C952_H
#define C952_H
#include<iostream>
using namespace std;
/*
* ��������
*
* ��һ��ת��������ת������n��
* n��������n = 3n + 1
* n��ż����n = n / 2
* �������ɴ�ת����n����1��
* ���ڸ�һ��n�������ת����1��Ҫ�Ĵ�����
* ע������
* 1 <= n <= 1000000
* ����
* ���� n = 2, ���� 1.
* ����:
* 2��1
* ���� n = 3, ���� 7.
* ����:
* 3��10��5��16��8��4��2��1
*/
class Solution {
public:
	/**
	* @param n: the number n
	* @return: the times n convert to 1
	*/
	int digitConvert(int n) {
		// Write your code here 
		int cnt = 0;
		//����ʹ��λ����
		while (n != 1)
		{
			if (n & 1 == 1)
				n = 3 * n + 1;
			else
				n = n >> 1;
			cnt++;
		}
		return cnt;
	}
};
#endif