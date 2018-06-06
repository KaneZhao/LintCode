#ifndef C391_H
#define C391_H
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
/*
* 数飞机
*
* 给出飞机的起飞和降落时间的列表，用 interval 序列表示. 请计算出天上同时最多有多少架飞机？
* 注意事项
* 如果多架飞机降落和起飞在同一时刻，我们认为降落有优先权。
* 样例
* 对于每架飞机的起降时间列表：[[1,10],[2,3],[5,8],[4,7]], 返回3。
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
class Solution {
public:
	/**
	* @param airplanes: An interval array
	* @return: Count of airplanes are in the sky.
	*/
	int countOfAirplanes(vector<Interval> &airplanes) {
		// write your code here
		if (airplanes.empty())
			return 0;
		int temp = 0;
		int num = 0;
		map<int, int> m;//存放时间点和仅考虑当前时间点在天上的飞机数
		set<int> set;
		for (auto c : airplanes)
		{
			m[c.start]++;//start表示飞机升空,数目加一
			m[c.end]--;//end表示降落,数目减一
			set.insert(c.start);//将起降的时间点都存入到set中
			set.insert(c.end);
		}
		//遍历set,取出最大飞机数
		for (auto c : set)
		{
			temp += m[c];
			if (temp < 0)
				temp = 0;
			if (num < temp)
				num = temp;
		}
		return num;
	}
};
#endif