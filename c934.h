#ifndef C934_H
#define C934_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 开锁问题
*
* n把钥匙（编号1-n），m把锁（编号1-m），当锁的号码能够被钥匙的号码整除的时候，该锁就可以被打开/关闭。最初所有的锁都是锁住的状态，然后用所有的钥匙去开所有的锁，返回有几把锁最后是打开的。
* 注意事项
* 1 <= m, n <= 10^5
* 样例
* 给出 n = 1, m = 1, 返回 1。
* 解释：
* 编号为1的锁被打开了
* 给出 n = 2, m = 5, 返回3。
* 解释：
* 编号为1,3,5的锁被打开了
*/
class Solution {
public:
	/**
	* @param n: the number of keys
	* @param m: the number of locks
	* @return: the numbers of open locks
	*/
	int unlock(int n, int m) {
		// Write your code here
		int res = 0;
		vector<int> nums(m + 1, 0);
		//对于1~n找到小于m且可以整除的数i*j,且nums[i*j]+1
		for (int i = 1; i <= n; ++i)
		{
			int j = 1;
			while (i*j <= m)
			{
				nums[i*j]++;
				++j;
			}
		}
		//只有在进行开关锁奇数次的情况下,对应编号的锁才是打开的
		for (auto c : nums)
		{
			if (c % 2 == 1)
				res++;
		}
		return res;
	}
};
#endif