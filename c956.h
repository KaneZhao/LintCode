#ifndef C956_H
#define C956_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* ���ݷָ�
*
* ����һ���ַ��� str,����Ҫ��˳����ȡ�����ַ����ķ��ź͵��ʡ�
* ע������
* str���Ȳ��ᳬ��10000��
* �ַ���ֻ����Сд��ĸ�����źͿո�
* ����
* ���� str = "(hi (i am)bye)"������ ["(","hi","(","i","am",")","bye",")"]��
* ���ͣ�
* �����ź͵��ʷָ
*/
class Solution {
public:
	/**
	* @param str: The input string
	* @return: The answer
	*/
	vector<string> dataSegmentation(string &str) {
		// Write your code here
		vector<string> res;
		if (str.empty())
			return res;
		string temp;
		//�����ַ���.������ĸtemp���ϵ�ǰ�ַ�,ֱ�������ո�������,��ӵ�res
		//����������,�õ�ǰ�ַ���ֵtemp,��ӵ�res
		//�����ո�,����
		for (int i = 0; i < str.size(); ++i)
		{
			if (ispunct(str[i]))
			{
				if (!temp.empty())
					res.push_back(temp);
				temp = str[i];
				res.push_back(temp);
				temp.clear();
			}
			else if (isalpha(str[i]))
			{
				temp += str[i];
			}
			else
			{
				if (!temp.empty())
					res.push_back(temp);
				temp.clear();
			}
		}
		if (!temp.empty())
			res.push_back(temp);
		return res;
	}
};
#endif