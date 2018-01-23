#ifndef c749_H
#define C749_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* John's backyard garden
*
* John wants to build a back garden on the empty space behind his home. There are two kinds of bricks now, one is 3 dm high and the other is 7 dm high. John wants to enclose a high x dm wall. If John can do this, output YES, otherwise NO.
* 注意事项
* X is an integer, and it's range is [3, 1000].
* 样例
* Give x = 10,return YES.
* Explanation:
* x = 3 + 7:That is, you need one batch of 3 dm height bricks and one batch of 7 dm height bricks.
* Give x = 5,return NO.
* Explanation:
* John can not enclose a high 5 dm wall with 3 dm height bricks and 7 dm height bricks.
* Give x = 13,return YES.
* Explanation:
* x = 2 * 3 + 7:That is, you need two batch of 3 dm height bricks and one batch of 7 dm height bricks.
*/
class Solution {
public:
	/**
	* @param x: the wall's height
	* @return: YES or NO
	*/
	string isBuild(int x) {
		// write you code here
		vector<int> dp(x + 1, 0);
		dp[3] = 1;
		//dp[i]=1,在dp[i-3]=1或dp[i-7]=1的情况下成立
		for (int i = 4; i <= x; ++i)
		{
			if (i == 7)
				dp[i] = 1;
			else
			{
				if (dp[i - 3] == 1 || (i > 7 && dp[i - 7] == 1))
					dp[i] = 1;
			}
		}
		return dp[x]==1?"YES":"NO";
	}
};
#endif