#ifndef C719_H
#define C719_H
#include<iostream>
#include<string>
using namespace std;
/*
*�������ֵ
*
*��һ���ַ������͵�����, дһ������ȥ�ҵ����ֵ, ������������������ּ�� + �� *
*
*����
*���� str = 01231, ���� 10 ((((0 + 1) + 2) * 3) + 1) = 10 ���ǵõ������ֵ 10
*���� str = 891, ���� 73 ��Ϊ 8 * 9 * 1 = 72 �� 8 * 9 + 1 = 73, ����73�����ֵ
*/
class Solution {
public:
	/*
	* @param : the given string
	* @return: the maximum value
	*/
	int calcMaxValue(string &str) {
		// write your code here
		if (str.empty())
			return 0;
		int res = 0;
		//�����ַ�����ÿһλ��ת��Ϊ����num��������ǰ�Ľ��res��Ϊmax{res*num,res+num},��󷵻�res
		for (int i = 0; i < str.size(); ++i)
		{
			int num = stoi(str.substr(i, 1));
			res = maxVal(res*num, res + num);
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif