#ifndef C662_H
#define C662_H
#include<iostream>
using namespace std;
/*
* 猜数游戏
*
* 我们正在玩猜数游戏。 游戏如下：
* 我从 1 到 n 选择一个数字。 你需要猜我选择了哪个号码。
* 每次你猜错了，我会告诉你这个数字是高还是低。
* 你调用一个预定义的接口 guess(int num)，它会返回 3 个可能的结果(-1，1或0):
* 样例
* n = 10, 我选择了 4 (但是你不知道)
* 返回 4。正确！
*/
class Solution {
public:
	/**
	* @param n an integer
	* @return the number you guess
	*/
	int guessNumber(int n) {
		// Write your code here
		int low = 1, high = n;
		while (low<=high)
		{
			int mid = low + (high - low) / 2;
			int m = guess(mid);
			if (m == 1)
				low = mid + 1;
			else if (m == 0)
				return mid;
			else
				high = mid - 1;
		}
	}
	/*
	int guess(int num)
	{
		if (num > goal)
			return -1;
		else if (num == goal)
			return 0;
		else
			return 1;
	}
	int goal;
	*/
};
#endif