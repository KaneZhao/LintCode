#ifndef C832_H
#define C832_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 统计负数
*
* 给一个横向排序的且纵向也排序的的 n * m的矩阵， 问里面有几个负数
* 注意事项
* 输入的矩阵大小为 n x m ，n <= 500，m <= 500。
* 为了约束程序的时间复杂度，你的程序将会运行 10^5 次
* 样例
* Given mat =
* [
* [-5,-3,-1,0,1],
* [-2,-1,0,0,1],
* [0,11,12,12,14]
* ],
* return 5.
* Explanation:
* There are only 5 negative number.
*/
class Solution {
public:
	/**
	* @param nums: the sorted matrix
	* @return: the number of Negative Number
	*/
	int countNumber(vector<vector<int>> &nums) {
		// Write your code here
		if (nums.empty() || nums[0].empty())
			return 0;
		int row = nums.size(), col = nums[0].size();
		int i = 0, j = col - 1;
		int cnt = 0;
		//判断数组右上角数是否为负数
		//若不是负数,则本列没有负数,去前一列寻找
		//若是负数,在本行次数之前的数都是负数,之后去下一行寻找
		while (i < row&&j >= 0)
		{
			if (nums[i][j] >= 0)
				j--;
			else
			{
				cnt += (j + 1);
				i++;
			}
		}
		return cnt;
	}
};
#endif 