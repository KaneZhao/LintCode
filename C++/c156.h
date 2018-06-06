#ifndef C156_H
#define C156_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 合并区间
* 
* 描述
* 给出若干闭合区间，合并所有重叠的部分。
* 样例
* Given intervals => merged intervals:
* [                     [
* (1, 3),               (1, 6),
* (2, 6),      =>       (8, 10),
* (8, 10),              (15, 18)
* (15, 18)            ]
* ]
* 挑战
* O(n log n) 的时间和 O(1) 的额外空间。
*/
class Interval{
public:
	int start, end;
	Interval(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};
bool comp(const Interval &a, const Interval &b)
{
	return a.start < b.start;
}
class Solution {
public:
	/**
	* @param intervals: interval list.
	* @return: A new interval list.
	*/
	vector<Interval> merge(vector<Interval> &intervals) {
		// write your code here
		if (intervals.empty())
			return intervals;
		sort(intervals.begin(), intervals.end(),comp);
		int len = intervals.size();
		int i = 0;
		while (i < len-1)
		{
			if (intervals[i].end>=intervals[i+1].end)
			{
				intervals[i + 1] = intervals[i];
				intervals.erase(intervals.begin() + i);
				len--;
			}
			else if (intervals[i].end >= intervals[i + 1].start)
			{
				intervals[i + 1].start = intervals[i].start;
				intervals.erase(intervals.begin() + i);
				len--;
			}
			else
			{
				i++;
			}
		}
		return intervals;
	}
	
};
#endif