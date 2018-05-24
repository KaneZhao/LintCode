#ifndef C735_H
#define C735_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 给一整数数组, 用当前元素之后数组中的最大元素来替换当前元素(右侧的最大元素). 因为最后一个元素的右边没有元素了, 
* 所以用 -1 来替换这个值. 举个例子, 如果数组为 [16,17,4,3,5,2], 那么它就需要修改为 [17,5,5,5,2,-1].
*/
class Solution {
public:
	/*
	* @param : An array of integers.
	* @return: nothing
	*/
	void arrayReplaceWithGreatestFromRight(vector<int> &nums) {
		// Write your code here.
		if (nums.empty())
			return;
		int len = nums.size();
		int num = nums[len - 1];
		nums[len - 1] = -1;
		for (int i = len - 2; i >= 0; --i)
		{
			int tmp = nums[i];
			nums[i] = num;
			if (tmp > num)
				num = tmp;
		}
	}
};
#endif