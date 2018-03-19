#ifndef C142_H
#define C142_H
#include<iostream>
using namespace std;
/*
* O(1)ʱ����2���ݴ�
*
* �� O(1) ʱ�������� n �Ƿ��� 2 ���ݴΡ�
* ����
* n=4������ true;
* n=5������ false.
* ��ս
* O(1) time
*/
class Solution {
public:
	/*
	* @param n: An integer
	* @return: True or false
	*/
	//���õݹ�,�ж��Ƿ���Ա�������2����
	bool checkPowerOf2(int n) {
		// write your code here
		if (n == 1)
			return true;
		if (n <= 0)
			return false;
		if (n % 2 != 0)
			return false;
		else
		{
			if (checkPowerOf2(n >> 1))
				return true;
		}
	}
};
class Solution2 {
public:
	/**
	* @param n: An integer
	* @return: True or false
	*/
	//2�Ĵ���,�����Ʊ�ʾֻ��һ��1���������
	//n&(n-1)�������е�1,ֵΪ0
	bool checkPowerOf2(int n) {
		// write your code here
		if (n <= 0)
			return false;
		return (n&(n - 1)) == 0 ? true: false;
	}
};
#endif