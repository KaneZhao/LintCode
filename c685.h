#ifndef C685_H
#define C685_H
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
/*
* 给一个连续的数据流,写一个函数返回终止数字到达时的第一个唯一数字（包括终止数字）,
* 如果在终止数字前无唯一数字或者找不到这个终止数字, 返回 -1.
* 
* 样例
* 给一个数据流 [1, 2, 2, 1, 3, 4, 4, 5, 6] 以及一个数字 5, 返回 3
* 给一个数据流 [1, 2, 2, 1, 3, 4, 4, 5, 6] 以及一个数字 7, 返回 -1
*/
class Solution {
public:
	/*
	* @param : a continuous stream of numbers
	* @param : a number
	* @return: returns the first unique number
	*/
	int firstUniqueNumber(vector<int> nums, int number) {
		// Write your code here
		if (nums.empty())
			return -1;
		set<int> dic;    //存放出现的所有数字
		set<int> set;    //存放至少两次出现的数字
		queue<int> que;  //存放第一次出现的数字
		bool flag = true;//判断是否找到number
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != number)
			{
				if (dic.find(nums[i]) == dic.end())
				{
					que.push(nums[i]);
					dic.insert(nums[i]);
				}
				else
				{
					set.insert(nums[i]);
					//只要队头元素出现在set中,就删除
					while (!que.empty()&&set.find(que.front()) != set.end())
					{
						que.pop();
					}
				}
			}
			else
			{
				flag = false;
				//若number第一次出现,入队;否则,若等于队头,则删除队头
				if (dic.find(nums[i]) == dic.end())
					que.push(nums[i]);
				else
				{
					if (que.front() == nums[i])
						que.pop();
				}
				break;
			}
		}
		if (flag)
			return -1;
		else
			return que.empty() ? -1 : que.front();
	}
};
#endif