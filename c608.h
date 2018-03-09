#ifndef C608_H
#define C608_H
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
* 两数和-输入已排序的数组
*
* 给定一个已经按升序排列的数组，找到两个数使他们加起来的和等于特定数。
* 函数应该返回这两个数的下标，index1必须小于index2。注意返回的值不是 0-based。
* 注意事项
* 你可以假设每个输入刚好只有一个答案
* 样例
* 给定数组为 [2,7,11,15] ，target = 9
* 返回 [1,2]
*/
class Solution {
public:
	/*
	* @param nums: an array of Integer
	* @param target: target = nums[index1] + nums[index2]
	* @return: [index1 + 1, index2 + 1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		vector<int> res;
		map<int, int> map;//存放元素与其出现次数
		for (auto c : nums)
		{
			map[c]++;
		}
		int pos1 = 0, pos2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			map[nums[i]]--;
			//在map中找到与nums[i]和为target的数,并且保证数存在
			if (map.find(target - nums[i]) != map.end() && map[target - nums[i]]>0)
			{
				pos1 = i;
				break;
			}
			map[nums[i]]++;
		}
		//从后向前遍历,找到target-nums[pos1]
		for (int j = nums.size() - 1; j >= 0; --j)
		{
			if (nums[j] == target - nums[pos1])
			{
				pos2 = j;
				break;
			}
		}
		res.push_back(pos1 + 1);
		res.push_back(pos2 + 1);
		return res;
	}
};
#endif