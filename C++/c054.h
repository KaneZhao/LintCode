#ifndef C54_H
#define C54_H
#include<iostream>
#include<string>
#include <math.h>
using namespace std;
/*
* String to Integer (atoi)
*
* ʵ��atoi�����������һ���ַ���ת��Ϊ���������û�кϷ�������������0���������������32λ�����ķ�Χ������INT_MAX(2147483647)�����������������INT_MIN(-2147483648)����Ǹ�������
* ����
* "10" =>10
* "-1" => -1
* "123123123123123" => 2147483647
* "1.0" => 1
*/
class Solution {
public:
	/**
	* @param str: A string
	* @return: An integer
	*/
	int atoi(string &str) {
		// write your code here
		if (str.empty())
			return 0;
		long long res = 0;
		bool isNeg = false;
		string nums("0123456789");
		int posNum = 0;
		//�ҵ���һ�����ֳ��ֵ�λ��
		if (str.find_first_of(nums) != string::npos)
			posNum = str.find_first_of(nums);
		else
			return 0;
		//����һ������ǰ�����ǿո�,-����+,���Ϸ�
		if (posNum > 0 && str[posNum - 1] != ' ' && str[posNum - 1] != '-' && str[posNum-1] != '+')
			return 0;
		//���ַ�����ʼ����һ����ĸ��ǰһ��λ��֮ǰ,ֻ���ǿո�,���򲻺Ϸ�
		for (int i = 0; i< posNum - 1; ++i)
		{
			if (str[i] != ' ')
				return 0;
		}
		//�ж��Ƿ��Ǹ���
		if (posNum>0 && str[posNum - 1] == '-')
			isNeg = true;
		str = str.substr(posNum);
		//Ѱ�ҺϷ����ֵĽ���λ��,���������־ͽ���(������С������)
		int end = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (isdigit(str[i]))
			{
				end = i;
			}
			else
				break;
		}
		//������ȡ���ĺϷ�����,������ֵ
		str = str.substr(0, end + 1);
		for (int j = 0; j <str.size(); ++j)
			res += (str[j] - '0')*pow(10, str.size() - 1 - j);
		if (isNeg)
			res = -res;
		if (res > INT_MAX)
			res = INT_MAX;
		else if (res < INT_MIN)
			res = INT_MIN;
		return res;
	}
};
#endif