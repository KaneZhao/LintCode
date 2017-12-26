#ifndef C692_H
#define C692_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 滑动窗口内唯一元素数量和
*
* 给一个数组和一个滑动窗口的大小, 求每一个窗口内唯一元素的个数和
* 样例
* 给一个数组 nums = [1, 2, 1, 3, 3] 和 k = 3
* 第一个窗口为 [1, 2, 1], 只有 2 是唯一的, 计数为 1.
* 第二个窗口为 [2, 1, 3], 所有的元素都是唯一的, 计数为 3.
* 第三个窗口为 [1, 3, 3], 只有 1 是唯一的, 计数为 1.
* 总数为 1 + 3 + 1 = 5
* 返回 5
*/
class Solution {
public:
	/*
	* @param : the given array
	* @param : the window size
	* @return: the sum of the count of unique elements in each window
	*/
	int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
		// write your code here
		if (nums.empty() || k <= 0)
			return 0;
		int len = nums.size();
		map<int, int> m;
		int res = 0;
		if (k == 1)//窗口大小为1,每个窗口内的个数为1
			return len;
		else if (k >= len)//当k>=len,就相当于求nums中唯一元素的个数
		{
			for (auto c : nums)
				m[c]++;
			for (auto t : m)
			{
				if (t.second == 1)
					res++;
			}
			return res;
		}
		else
		{
			int cnt = 0;
			//i=0,构建map表示窗口内每个出现元素的个数
			for (int l = 0; l < k; ++l)
				m[nums[l]]++;
			for (auto t : m)
			{
				if (t.second == 1)
					cnt++;
			}
			res += cnt;
			//对于i,更新m以及cnt
			//将m[nums[i-1]]自减,若值为1,则之前nums[i-1]出现次数为2,cnt++
			//若值为0,则之前nums[i-1]出现次数为1,现在窗口没有nums[i-1],cnt--
			//其他情况不影响cnt的值
			for (int i = 1; i + k <= len; ++i)
			{
				m[nums[i - 1]]--;
				if (m[nums[i - 1]] == 1)
					cnt++;
				else if (m[nums[i-1]]==0)
					cnt--;
				m[nums[i + k - 1]]++;
				if (m[nums[i + k - 1]] == 1)
					cnt++;
				else if (m[nums[i+k-1]]==2)
					cnt--;
				res += cnt;
			}
			return res;
		}
	}
};
#endif