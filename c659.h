#ifndef C659_H
#define C659_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 字符串序列化
*
* 设计一个将字符串列表编码为字符串的算法。 已经编码的字符串之后会通过网络发送同时也会被解码回到原始的字符串列表。
* 请实现 encode 和 decode
* 样例
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
		//对于每个字符,求出其与' '的差值,并将差值转化为长度3的字符串并添加到res
		//若当前的字符串遍历完毕,res添加"###"
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
		//将字符串分解,每三位表示一个字符,在遇到"###"之前依次添加到words
		//遇到"###",说明已经解码出一个字符串,将其添加到res
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