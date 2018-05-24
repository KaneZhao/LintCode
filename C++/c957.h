#ifndef C957_H
#define C957_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 雷达检测
*
* 一个2D平面上有一堆雷达（雷达有x, y坐标，以及能探测到的范围r半径）。现在有一辆小车要从y = 0和y = 1的区间里面通过并且不能被雷达探测到。若被检测到，输出YES，否则输出NO。（可以认为，小车是一条长度为1的线段，沿直线从x = 0 向右前进）
* 注意事项
* 雷达数量为n，n <= 1000。
* 雷达的坐标x为非负整数，y为整数，r为正整数。
* 样例
* 给出 coordinates = [[0,2]], radius = [1], 返回 "NO"。
* 解释：
* 在(0,2)处有个雷达，它能探测到以(0,2)为圆心，半径为1的圆形区域，小车不会被检测到。
*/
struct Point{
	int x;
	int y;
	Point() :x(0), y(0){}
	Point(int a, int b) :x(a), y(b){}
};
class Solution {
public:
	/**
	* @param coordinates: The radars' coordinate
	* @param radius: Detection radius of radars
	* @return: The car was detected or not
	*/
	string radarDetection(vector<Point> &coordinates, vector<int> &radius) {
		// Write your code here
		if (coordinates.empty() || radius.empty())
			return "NO";
		int len = coordinates.size();
		for (int i = 0; i < len; ++i)
		{
			if (isDetected(coordinates[i].y, radius[i]))
			{
				return "YES";
			}
		}
		return "NO";
	}
	//判断是否会检测到,只与y坐标的值有关
	bool isDetected(int y, int radius)
	{
		if (y >= 0 && y <= 1)
			return true;
		else if (y > 1)
		{
			if (y - radius < 1)
				return true;
			else
				return false;
		}
		else
		{
			if (y + radius>0)
				return true;
			else
				return false;
		}
	}
};
#endif