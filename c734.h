#ifndef C734_H
#define C734_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* ��ʽΪa^i b^j c^k������������
*
* ��һ�ַ���, ����ʽΪ a^i b^j c^k �������н��м���, ������ i ���ַ� a, ������ j ���ַ� b, Ȼ���� k ���ַ� c���, i >= 1, j >= 1, k >= 1.
* Note: ���������������ԭ�ַ����е�index�����ǲ�ͬ�ģ�����Ϊ���������в�ͬ��
*
* ����
* ���� s = abbc, ���� 3 ������Ϊ abc, abc �� abbc
* ���� s = abcabc, ���� 7 ������Ϊ abc, abc, abbc, aabc, abcc, abc �� abc
*/
class Solution {
public:
	/*
	* @param : the input string
	* @return: the number of subsequences
	*/
	int countSubsequences(string &source) {
		// write your code here
		int a = 0, b = 0, c = 0;
		for (auto t : source)
		{
			if (t == 'a')
				a = 2 * a + 1;//ÿ��a����ȡ��ǰ���a,���߸���ǰһ����a,������Ϊ�µĿ�ʼ
			else if (t == 'b')
				b = a + 2 * b;//ÿ��b���Ը���ǰ���a,���߸���ǰһ����b,����ȡ��ǰһ����b
			else if (t == 'c')
				c = b + c * 2;//ÿ��c���Ը���ǰ���b,���߸���ǰһ����c,����ȡ��ǰһ����c
		}
		return c;
	}
};
#endif