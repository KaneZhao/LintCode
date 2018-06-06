#ifndef C1397_H
#define C1397_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
/*
* 覆盖数字
*
* 描述
* 给出一些区间，问覆盖次数最多的数是多少，如果有多个，输出最小的那个数。
* 区间的个数不大于10^5。
* 区间的左右端点大于0小于等于10^5。
* 样例
* 给出 intervals = [(1,7),(2,8)], 返回 2。
* 解释：
* 2被覆盖了2次，且是覆盖2次中最小的数。
* 给出 intervals = [(1,3),(2,3),(3,4)], 返回 3。
* 解释：
* 3被覆盖了3次。
*/
class Interval{
public:
	int start, end;
	Interval(int start, int end){
		this->start = start;
		this->end = end;
	}
};
class Solution {
public:
	/**
	* @param intervals: The intervals
	* @return: The answer
	*/
	int digitalCoverage(vector<Interval> &intervals) {
		// Write your code here
		if (intervals.empty())
			return 0;
		map<int, int> m;//存放元素和当前集合的个数
		set<int> nums;
		int num = 0;
		int temp = 0;
		int cnt = 0;
		for (auto c : intervals)
		{
			++m[c.start];
			--m[c.end + 1];//由于end被覆盖,end+1没有被覆盖,要处理的值是end+1
			nums.insert(c.start);
			nums.insert(c.end + 1);
		}
		//找到最大覆盖次数对应的元素
		for (auto c : nums)
		{
			temp += m[c];
			if (temp < 0)
				temp = 0;
			if (temp>cnt)
			{
				cnt = temp;
				num = c;
			}
		}
		return num;
	}
	
};
#endif