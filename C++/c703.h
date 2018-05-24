#ifndef C703_H
#define C703_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
折叠数组

给一个长度为 n 的数组 nums 和一个长度为 k 的数组 req, 你需要根据要求折叠数组，并输出折叠的结果
1.如果 req[i] = 0 意味着你应该从左到右折叠, 例如:

1 2 3 4 5 6 7 8  ==>   4 3 2 1
5 6 7 8
2.如果 req[i] = 1 意味着你应该从右往左折叠, 例如:

1 2 3 4 5 6 7 8  ==>   8 7 6 5
1 2 3 4
更多的例子:

从左到右折叠
4 3 2 1  ==>  6 5
5 6 7 8       3 4
2 1
7 8


从右到左折叠
6 5  ==>   8
3 4        1
2 1        4
7 8        5
6
3
2
7
注意事项

n 为 2 的幂
k 是指数.(例如 n = 2^3 = 8，k = 3)

样例
给出数组 nums = [1, 2, 3, 4, 5, 6, 7, 8] 和 数组 req = [0, 0, 1] 原地改变元素位置为 [8, 1, 4, 5, 6, 3, 2, 7]
*/
class Solution {
public:
	/*
	* @param : the original array
	* @param : the direction each time
	* @return: the final folded array
	*/
	vector<int> folding(vector<int> &nums, vector<int> &req) {
		// write your code here
		int len = req.size();
		for (int i = 0; i < len; ++i)
		{
			if (req[i] == 0)
				left(nums, (int)pow(2, i));
			else
				right(nums, (int)pow(2, i));
		}
		return nums;
	}
	//从左向右折叠，将数组的前半部分反向，根据长度len的大小，将前半部分与后半部分按照相对顺序组合成新的数组。 
	void left(vector<int> &nums, int len)
	{
		vector<int> res;
		int n = nums.size() / (len*2);
		reverse(nums.begin(), nums.begin() + nums.size()/2);
		for (int i = 0; i < n; ++i)
		{
			res.insert(res.end(), nums.begin() + i*len, nums.begin() + i*len + len);
			res.insert(res.end(), nums.begin() + i*len + nums.size()/2, nums.begin() + i*len + len + nums.size()/2);
		}
		nums = res;
	}
	//从右向左折叠，将数组的后半部分反向，根据长度len的大小，将后半部分与前半部分按照相对顺序组合成新的数组。
	void right(vector<int> &nums, int len)
	{
		vector<int> res;
		int n = nums.size() / (len * 2);
		reverse(nums.begin() + nums.size() / 2, nums.end());
		for (int i = 0; i < n; ++i)
		{		
			res.insert(res.end(), nums.begin() + i*len + nums.size() / 2, nums.begin() + i*len + len + nums.size() / 2);
			res.insert(res.end(), nums.begin() + i*len, nums.begin() + i*len + len);
		}
		nums = res;
	}
};
#endif