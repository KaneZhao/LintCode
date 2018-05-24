#ifndef C181_H
#define C181_H
#include<iostream>
using namespace std;
/*
* ������Aת��ΪB
* 
* ���Ҫ������Aת��ΪB����Ҫ�ı���ٸ�bitλ��
* ע������
* Both n and m are 32-bit integers.
* ����
* ���31ת��Ϊ14����Ҫ�ı�2��bitλ��
* (31)10=(11111)2
* (14)10=(01110)2
*/
class Solution {
public:
	/**
	*@param a, b: Two integer
	*return: An integer
	*/
	int bitSwapRequired(int a, int b) {
		// write your code here
		//ȡab�����,�õ��Ķ�������1�ĸ���������Ҫ�ı��λ��
		int temp = a^b;
		int cnt = 0;
		//������Ҫ�ı��λ��
		while (temp)
		{
			temp &= (temp - 1);
			cnt++;
		}
		return cnt;
	}
};
#endif