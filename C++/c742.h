#ifndef C742_H
#define C742_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
*Digit Divide Numbers
*
* A Digit Divide Numbers is a number that is divisible by every digit it contains.
* For example, 128 is a Digit Divide Numbers because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
* Also, Digit Divide Numbers is not allowed to contain the digit zero.
* Given a lower and upper number bound, output a list of every possible Digit Divide Numbers, including the bounds if possible.
* 注意事项
* 0<=L<=R<=2^31-1,R-L<=10^6
* 样例
* Given left = 1, right = 22, return [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
*/
class Solution {
public:
	/**
	* @param lower: Integer : lower bound
	* @param upper: Integer : upper bound
	* @return: a list of every possible Digit Divide Numbers
	*/
	vector<int> digitDivideNums(int lower, int upper) {
		// write your code here
		vector<int> res;
		for (long long i = lower; i <= upper; ++i)
		{
			if (isDigitDivideNum(i))
				res.push_back(i);
		}
		return res;
	}
	//判断此数字是否是Digit Divide Numbers
	bool isDigitDivideNum(long long num)
	{
		string str = to_string(num);
		for (int i = 0; i < str.size(); ++i)
		{
			if (str.substr(i, 1) == "0")
				return false;
			if (num % (stoi(str.substr(i, 1))) != 0)
				return false;
		}
		return true;
	}
};
#endif