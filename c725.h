#ifndef C725_H
#define C725_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	/*
	* @param symb: the array of symbols
	* @param oper: the array of operators
	* @return: the number of ways
	*/
	int countParenth(string &symb, string &oper) {
		// write your code here
		int len = symb.size();
		vector<vector<int>> vecT(len, vector<int>(len, 0));//vecT[i][j]表示在i-j之间的表达式中结果为true的方式数
		vector<vector<int>> vecF(len, vector<int>(len, 0));//vecT[i][j]表示在i-j之间的表达式中结果为false的方式数
		for (int i = 0; i < len; ++i)
		{
			if (symb[i] == 'T')
				vecT[i][i] = 1;
			else
				vecF[i][i] = 1;
		}
		for (int path = 1; path < len; ++path)
		{
			for (int i = 0, j = path; j < len; ++i, ++j)
			{
				for (int n = 0; n < path; ++n)
				{
					int k = i + n;
					int total = (vecT[i][k] + vecF[i][k])*(vecT[k + 1][j] + vecF[k + 1][j]);
					if (oper[k] == '&')
					{
						vecT[i][j] += vecT[i][k] * vecT[k + 1][j];
						vecF[i][j] += total - vecT[i][k] * vecT[k + 1][j];
					}
					else if (oper[k] == '|')
					{
						vecT[i][j] += total - vecF[i][k] * vecF[k + 1][j];
						vecF[i][j] += vecF[i][k] * vecF[k + 1][j];
					}
					else
					{
						vecT[i][j] += vecT[i][k] * vecF[k + 1][j] + vecT[k + 1][j] * vecF[i][k];
						vecF[i][j] += vecT[i][k] * vecT[k + 1][j] + vecF[i][k] * vecF[k + 1][j];
					}
				}
			}
		}
		return vecT[0][len - 1];
	}
};
#endif