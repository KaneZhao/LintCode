#ifndef C1347_H
#define C1347_H
#include<iostream>
using namespace std;
/*
* β����
*
* ����
* ����һ������n������n!��n�Ľ׳ˣ���β����ĸ�����
* ���Ľⷨʱ�临�Ӷ�ӦΪ��������
*/
class Solution {
public:
	/**
	* @param n: a integer
	* @return: return a integer
	*/
	int trailingZeroes(int n) {
		// write your code here
		int cnt = 0;
		//����2��5�����γ�0,��2�ĸ������Ƕ���5,����0~n�е�������5�ĸ���
		while (n != 0)
		{
			cnt += n / 5;
			n = n / 5;
		}
		return cnt;
	}
};
#endif