#ifndef C659_H
#define C659_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* �ַ������л�
*
* ���һ�����ַ����б����Ϊ�ַ������㷨�� �Ѿ�������ַ���֮���ͨ�����緢��ͬʱҲ�ᱻ����ص�ԭʼ���ַ����б�
* ��ʵ�� encode �� decode
* ����
* Given strs = ["lint","code","love","you"]
* string encoded_string = encode(strs)
* return ["lint","code","love","you"] when you call decode(encoded_string)
*/
class Solution {
public:
	/*
	* @param strs: a list of strings
	* @return: encodes a list of strings to a single string.
	*/
	string encode(vector<string> &strs) {
		// write your code here
		//����ÿ���ַ�,�������' '�Ĳ�ֵ,������ֵת��Ϊ����3���ַ�������ӵ�res
		//����ǰ���ַ����������,res���"###"
		string res;
		for (auto c : strs)
		{
			string words;
			for (auto t : c)
			{
				string tmp = to_string(t - ' ');
				int len = tmp.size();
				if (len == 1)
					tmp = "00" + tmp;
				else if (len == 2)
					tmp = "0" + tmp;
				words += tmp;
			}
			res += words + "###";
		}
		return res;
	}

	/*
	* @param str: A string
	* @return: dcodes a single string to a list of strings
	*/
	vector<string> decode(string &str) {
		// write your code here
		vector<string> res;
		if (str.empty())
			return res;
		//���ַ����ֽ�,ÿ��λ��ʾһ���ַ�,������"###"֮ǰ������ӵ�words
		//����"###",˵���Ѿ������һ���ַ���,������ӵ�res
		string words;
		int i = 0;
		while (i < str.size())
		{
			if (str.substr(i, 3) == "###")
			{
				res.push_back(words);
				words.clear();
			}
			else
			{
				char c = ' ' + stoi(str.substr(i, 3));
				words += c;
			}
			i += 3;
		}
		return res;
	}
};
#endif