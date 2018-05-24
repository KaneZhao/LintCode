#ifndef C844_H
#define C844_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 数对统计
*
* 给一个<Point>的List p，求满足p[i].x+p[j].x和p[i].y+p[j].y（i < j)都能被2整除的(i,j)对数。
* 注意事项
* 输入的list长度len <= 10000。
* 样例
* 给出 p = [[1,2],[3,4],[5,6]], 返回 3。
* 解释：
* p[0],p[1],p[2]两两组合，他们x与y之和都能被2整除。
* 给出 p = [[0,3],[1,1],[3,4],[5,6]], 返回 1。
* 解释：
* 只有p[2]和p[3]组合，他们的x与y之和都能被2整除。
*/
class Point{
public:
	int x, y;
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};
class Solution {
public:
	/**
	* @param p: the point List
	* @return: the numbers of pairs which meet the requirements
	*/
	int pairNumbers(vector<Point> &p) {
		// Write your code here
		if (p.empty())
			return 0;
		int cnt = 0;
		int len = p.size();
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if ((p[i].x + p[j].x) % 2 == 0 && (p[i].y + p[j].y) % 2 == 0)
					cnt++;
			}
		}
		return cnt;
	}
};
#endif