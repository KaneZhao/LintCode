#ifndef C727_H
#define C727_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 中国剩余定理
*
* 给出两个数组 num[0..k - 1] 和 rem[0..k - 1]. 在数组num[0..k - 1]中, 所有的元素都是互质的( gcd 为 1 ). 我们需要找到满足下列条件的最小正数 x:
* x % num[0]    =  rem[0],
* x % num[1]    =  rem[1],
.......................
* x % num[k-1]  =  rem[k-1]
* 样例
* 给出 nums = [3,4,5], rems = [2,3,1], 返回 11
* 11 是满足以下条件的最小值:
- 除以 3, 得到余数 2.
- 除以 4, 得到余数 3.
- 除以 5, 得到余数 1.
*/
class Solution {
public:
	/**
	* @param num: the given array
	* @param rem: another given array
	* @return: The minimum positive number of conditions to meet the conditions
	*/
	//将数字表示为m=i∗n+r，遍历数组，并不断更新n和r的值，若对于下一位置j+1，m%num[j+1]=rem[j+1]，跟新n的值，保留r的值
	int remainderTheorem(vector<int> &num, vector<int> &rem) {
		// write your code here
		if (num.empty() || rem.empty())
			return 0;
		int len = num.size();
		int n = num[0];
		int r = rem[0];
		for (int i = 1; i < len; ++i)
		{
			int a = (rem[i] - r%num[i] + num[i]) % num[i];
			if (a != 0)
			{
				for (int j = 1; j <= num[i]; ++j)
				{
					if (n*j%num[i] == a)
					{
						r = n*j + r;
						break;
					}
				}
			}
			n = num[i] * n;
		}
		return r;
	}
};
#endif