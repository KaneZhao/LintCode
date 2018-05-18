#ifndef C1385_H
#define C1385_H
#include<iostream>
using namespace std;
/*
* ��������8
*
* ����
* 8��С�ŵ��������֣�С����֪����1~n�������ж��ٸ����ֺ���8��
* 1 <= n <= 1000000
* ����
* ���� n = 20�� ����2��
* ���ͣ�
* ֻ��8,18 ����8��
* ���� n = 100�� ����19��
* ���ͣ�
* ��8,18,28,38,48,58,68,78,80,81,82,83,84,85,86,87,88,89,98��
*/
class Solution {
public:
	/**
	* @param n: count lucky numbers from 1 ~ n
	* @return: the numbers of lucky number
	*/
	int luckyNumber(int n) {
		// Write your code here
		if (n <= 7)
			return 0;
		int num = 1;
		int i = 8;
		//��һ������8�����ֳ������ֻ���ܱ����ڵ����ִ�1,2,9��10
		while (i <= n)
		{
			if (hasEight(i+1))
			{
				i += 1;
				num++;
			}
			else if (hasEight(i + 2))
			{
				i += 2;
				num++;
			}
			else if (hasEight(i + 9))
			{
				i += 9;
				num++;
			}
			else if (hasEight(i + 10))
			{
				i += 10;
				num++;
			}
		}
		return --num;
	}
	//�ж��������Ƿ���8
	bool hasEight(int n)
	{
		while (n)
		{
			if (n % 10 == 8)
				return true;
			n = n / 10;
		}
		return false;
	}
};
#endif