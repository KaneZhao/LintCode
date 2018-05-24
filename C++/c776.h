#ifndef C776_H
#define C776_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* �Գ���II
*
* �Գ�����һ����ת180�Ⱥ�(������)��������ԭ����ͬ����.�ҵ����г���Ϊ n �ĶԳ���.
* ����
* ���� n = 2 ���� ["11","69","88","96"].
*/
class Solution {
public:
	/**
	* @param n: the length of strobogrammatic number
	* @return: All strobogrammatic numbers
	*/
	vector<string> findStrobogrammatic(int n) {
		// write your code here
		vector<string> res;
		if (n <= 0)
			return{""};
		res = helper(n);
		if (n == 1)
			return res;
		//ȥ��������0��ͷ���ַ���
		sort(res.begin(), res.end());
		int pos = 0;
		for (int i = 0; i < res.size(); ++i)
		{
			if (res[i][0] != '0')
			{
				pos = i;
				break; 
			}
		}
		if (pos != 0)
			res.erase(res.begin(), res.begin() + pos);
		return res;
	}
	//�ݹ����
	vector<string> helper(int n)
	{
		if (n == 1)
			return{ "0", "1", "8" };
		else if (n == 2)
			return{ "00","11", "69", "88", "96" };
		vector<string> res = helper(n - 2);
		vector<string> tmp = helper(2);
		vector<string> vec;
		//n�Ľ���͵�ͬ�ڽ�n=2��ÿ������ӵ�n-2ÿ�����������
		for (auto c : res)
		{
			for (auto t : tmp)
				vec.push_back(t[0] + c + t[1]);
		}
		return vec;
	}
};
#endif