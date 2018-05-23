#ifndef C517_H
#define C517_H
#include<iostream>
using namespace std;
/*
* ����
*
* ����
* дһ�����������һ�������ǲ��ǳ�����
* �����Ķ����ǣ�ֻ���������� 2, 3, 5 �������������� 6, 8 ���ǳ��������� 14 ���ǳ�����Ϊ�������������� 7��
* ������Ϊ 1 ��һ������ĳ�����
* ����
* ���� num = 8������ true��
* ���� num = 14������ false��
*/
class Solution {
public:
	/*
	* @param num: An integer
	* @return: true if num is an ugly number or false
	*/
	bool isUgly(int num) {
		// write your code here
		if (num <= 0)
			return false;
		if (num == 1)
			return true;
		if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
			return false;
		else
		{
			if (num % 2 == 0)
				return isUgly(num / 2);
			else if (num % 3 == 0)
				return isUgly(num / 3);
			else
				return isUgly(num / 5);
		}
	}
};
#endif