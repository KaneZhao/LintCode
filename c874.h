#ifndef C874_H
#define C874_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Maximum Vacation Days
*
* LintCode wants to give one of its best employees the option to travel among N cities to collect algorithm problems. But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks. Your job is to schedule the traveling to maximize the number of vacation days you could take, but there are certain rules and restrictions you need to follow.
* Rules and restrictions:
* 1. You can only travel among N cities, represented by indexes from 0 to N-1. Initially, you are in the city indexed 0 on Monday.
* 2. The cities are connected by flights. The flights are represented as a N*N matrix (not necessary symmetrical), called flights representing the airline status from the city i to the city j. If there is no flight from the city i to the city j, flights[i][j] = 0; Otherwise, flights[i][j] = 1. Also, flights[i][i] = 0 for all i.
* 3. You totally have K weeks (each week has 7 days) to travel. You can only take flights at most once per day and can only take flights on each week's Monday morning. Since flight time is so short, we don't consider the impact of flight time.
* 4. For each city, you can only have restricted vacation days in different weeks, given an N*K matrix called days representing this relationship. For the value of days[i][j], it represents the maximum days you could take vacation in the city i in the week j.
* You're given the flights matrix and days matrix, and you need to output the maximum vacation days you could take during K weeks.
*/
class Solution {
public:
	/**
	* @param flights: the airline status from the city i to the city j
	* @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
	* @return: the maximum vacation days you could take during K weeks
	*/
	int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
		// Write your code here
		int rows = days.size();
		int cols = days[0].size();
		//为了方便计算,将flights[i][i]置为1,表示可以到达
		for (int i = 0; i < flights.size(); ++i)
			flights[i][i] = 1;
		//dp[i][j]表示在第j周在城市i的情况下,累积最大的休息天数
		//初始值为-1,表示无法在第j周到达城市i
		vector<vector<int>> dp(rows, vector<int>(cols, -1));
		//由于开始位置0号城市,计算0周的最大休息天数
		for (int i = 0; i < rows; ++i)
		{
			if (flights[0][i] == 1)
			{
				dp[i][0] = days[i][0];
			}
		}
		//由于dp[i][j]表示在第j周在城市i的情况下,累积最大的休息天数
		//遍历j的前一列,求出从每个城市到i城市最大的休息天数
		//当飞机无法到达或者前一列元素值为-1时,表示此种情况无法满足,跳过
		for (int j = 1; j < cols; ++j)
		{
			for (int i = 0; i < rows; ++i)
			{
				int res = -1;
				for (int k = 0; k < rows; ++k)
				{
					if (flights[k][i] == 1&&dp[k][j-1]!=-1)
					{
						res = maxVal(res, dp[k][j - 1] + days[i][j]);
					}
				}
				dp[i][j] = res;
			}
		}
		int num = 0;
		for (int i = 0; i<rows; ++i)
		{
			if (dp[i][cols - 1]>num)
				num = dp[i][cols - 1];
		}
		return num;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif