#ifndef C140_H
#define C140_H
#include<iostream>
using namespace std;
/*
* ������
*
* ����an % b������a��b��n����32λ��������
* ����
* ���� 231 % 3 = 2
* ���� 1001000 % 1000 = 0
* ��ս
* O(logn)
*/
class Solution {
public:
	/*
	* @param a, b, n: 32bit integers
	* @return: An integer
	*/
	int fastPower(int a, int b, int n) {
		// write your code here
		if (b == 0||n < 0)
			return -1;
		if (n == 0)
			return 1 % b;
		if (n == 1)
			return a%b;
		long long res = fastPower(a, b, n >> 1)%b;//���ַ�
		res = (res*res) % b;
		//ע��nΪ���������
		if (n & 1 == 1)
			res = (res*a) % b;
		return res;
	}
};
#endif