#ifndef C745_H
#define C745_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* Palindromic Ranges
*
* A positive integer is a palindrome if its decimal representation (without leading zeros) is a palindromic string (a string that reads the same forwards and backwards). For example, the numbers 5, 77, 363, 4884, 11111, 12121 and 349943 are palindromes.
* A range of integers is interesting if it contains an even number of palindromes. The range [L, R], with L <= R, is defined as the sequence of integers from L to R (inclusive): (L, L+1, L+2, …, R-1, R). L and R are the range’s first and last numbers.
* The range [L1, R1] is a subrange of [L, R] if L <= L1 <= R1 <= R. Your job is to determine how many interesting subranges of [L, R] there are.
* 样例
* Given L = 1, R = 2, return 1
* Given L = 1, R = 7, return 12
* Given L = 87, R = 88, return 1
*/
class Solution {
public:
	/**
	* @param L: A positive integer
	* @param R: A positive integer
	* @return: the number of interesting subranges of [L, R]
	*/
	//计算包含偶数个回文数字的子区间的个数
	int PalindromicRanges(int L, int R) {
		// Write your code here
		string res;
		int range = R - L + 1;
		int cnt = 0;
		vector<int> v;//构建数组表示每个数字是否是回文数字
		for (int i = L; i <= R; ++i)
		{
			if (isPalindorme(to_string(i)))
				v.push_back(1);
			else
			{
				v.push_back(0);
				cnt++;
			}
		}
		for (int j = 1; j < range; ++j)
		{
			int num = v[j - 1];
			for (int k = j; k <range; ++k)
			{
				num += v[k];
				if (num % 2 == 0)
					cnt++;
			}
		}
		return cnt;
	}
	//判断是否为回文串
	bool isPalindorme(string str)
	{
		if (str.empty())
			return true;
		int l = 0, r = str.size() - 1;
		while (l < r)
		{
			if (str[l] != str[r])
				return false;
			l++;
			r--;
		}
		return true;
	}
};
#endif