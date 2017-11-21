#ifndef C690_H
#define C690_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	/*
	* @param : an integer
	* @return:  the factorial of n
	*/
	string factorial(int n) {
		// write your code here
		vector<int> res(200000, 0);
		int digit = 1,num = 0; //digit表示位数,num表示当前结果
		res[0] = 1;
		for (int i = 2; i <= n; ++i)
		{
			int tmp = 0;  //当前结果的进位
			for (int j = 0; j < digit; ++j)
			{
				num = res[j] * i + tmp;
				res[j] = num % 10;
				tmp = num / 10;
			}
			while (tmp) //tmp不为0,增加位数
			{
				res[digit] = tmp % 10;
				tmp = tmp / 10;
				digit++;
			}
		}
		string str;
		for (int i = 0; i < digit; ++i)
			str = to_string(res[i]) + str;
		return str;
	}
};
#endif