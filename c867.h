#ifndef C867_H
#define C867_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 4 Keys Keyboard
*
* Imagine you have a special keyboard with the following keys:
* Key 1: (A): Print one 'A' on screen.
* Key 2: (Ctrl-A): Select the whole screen.
* Key 3: (Ctrl-C): Copy selection to buffer.
* Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
* Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.
* 注意事项
* 1 <= N <= 50
* Answers will be in the range of 32-bit signed integer.
* 样例
* Given N = 3, return 3.
* Explanation:
* We can at most get 3 A's on screen by pressing following key sequence:
* A, A, A
* Given N = 7, return 9.
* Explanation:
* We can at most get 9 A's on screen by pressing following key sequence:
* A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
*/
class Solution {
public:
	/**
	* @param N: an integer
	* @return: return an integer
	*/
	int maxA(int N) {
		// write your code here
		if (N <= 5)
			return N;
		vector<int> dp(N + 1, 0);//dp[i]表示按N次键可以显示A的最多数目
		for (int i = 1; i <= 5; ++i)
			dp[i] = i;
		//位置j为Ctrl A,前面出现A的最多次数为dp[i-1]
		//后面进行Ctrl V的次数为i-j-1,出现A的数目为dp[i-1]*(i-j-1)
		//结果取和为dp[j-1]*(i-j)
		for (int i = 6; i <= N; ++i)
		{
			for (int j = 2; j < i; ++j)
			{
				dp[i] = maxVal(dp[i], dp[j - 1]*(i - j));
			}
		}
		return dp[N];
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif