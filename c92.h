#ifndef C92_H
#define C92_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @return: The maximum size
	*/
	int backPack(int m, vector<int> A) {
		// write your code here
		if (A.empty())
			return 0;
		vector<int> dp(m + 1, 0);
		for (int i = 0; i<A.size(); ++i)
		{
			for (int j = m; j >=1; --j)
			{
				if (j >= A[i])
				{
					dp[j] = maxVal(dp[j - A[i]] + A[i], dp[j]);
				}
			}
		}
		return dp[m];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif