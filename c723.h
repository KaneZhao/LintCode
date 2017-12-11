#ifndef C723_H
#define C723_H
#include<iostream>
#include<cmath>
using namespace std;
/*
* ����ת������λ
*
* λ��ת -���� ��ת����ѭ����λ������������λ�Ĳ���, ��ͬ����һ���������һλ�ᱻ�Żص���һ��
* ������ת��, ��˵���������һλ������Ҷ�
* ���� n �� 8 λ����������. �� n = 11100101 ����ת 3 λ, �õ� n = 00101111 (����3λ, ԭ�ȵ�ǰ3λ����ĩβ).
* ��� n �� 16 λ�� 32 λ����������, ��ô�� n (000��11100101)����ת��֮����� (00..0011100101000).
* �ڱ�������, ����Լ��� n ���� 32 λ�����������.
*/
class Solution {
public:
	/*
	* @param : a number
	* @param : digit needed to be rorated
	* @return: a number
	*/
	int leftRotate(int n, int d) {
		// write code here
		if (d < 0)
			return 0;
		d = d % 32;//��֤��0-31֮��
		long long num = pow(2, d) - 1;
		num = num << (32 - d);
		num = num&n;//��nȡ��,��ȡn�ĸ�dλ
		num = num >> (32 - d);//��num���Ƴ�dλ��,��Ϊn��dλ����ʾ����
		n = n << d;//n����dλ
		n += num;//����dλ��ʾ��������n���Ҷ�
		return n;
	}
};
#endif