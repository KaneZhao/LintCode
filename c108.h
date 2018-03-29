#ifndef C108_H
#define C108_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 分割回文串 II
*
* 给定一个字符串s，将s分割成一些子串，使每个子串都是回文。
* 返回s符合要求的的最少分割次数。
* 样例
* 比如，给出字符串s = "aab"，
* 返回 1， 因为进行一次分割可以将字符串s分割成["aa","b"]这样两个回文子串
*/
class Solution {
public:
	/**
	* @param s a string
	* @return an integer
	*/
	int minCut(string s) {
		// write your code here
		if (s.empty())
			return 0;
		int len = s.size();
		//dp[i][j]表示s[i,j]是否是回文串
		vector<vector<bool>> dp(len, vector<bool>(len,false));
		//sum[i]表示s[0,i]的最少分割次数
		vector<int> nums(len);
		//初始化sum,sum[i]=i
		for (int i = 0; i < len; ++i)
			nums[i] = i;
		//当字符串长度为1时,是回文串
		for (int i = 0; i < len; ++i)
			dp[i][i] = true;
		//设置步长,依次遍历每个位置
		//当前位置的字符相同且其内部的字符串是回文串(或者当前位置相邻),当前位置表示的字符串是回文串
		for (int path = 1; path < len; ++path)
		{
			for (int k = 0; k + path < len; ++k)
			{
				if (s[k] == s[k+path] && (dp[k + 1][k + path - 1]||path == 1))
					dp[k][k + path] = true;
			}
		}
		//若s[j,i]是回文串,则切割数为nums[j-1]+1
		for (int i = 1; i < len; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (dp[j][i])
				{
					if (j == 0)
						nums[i] = 0;
					else
						nums[i] = minVal(nums[i], nums[j - 1] + 1);
				}
			}
		}
		return nums[len - 1];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif