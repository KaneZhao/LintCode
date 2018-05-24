#ifndef C909_H
#define C909_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Android Unlock Patterns
*
* Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
* Rules for a valid pattern:
* 1. Each pattern must connect at least m keys and at most n keys.
* 2. All the keys must be distinct.
* 3. If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
* 4. The order of keys used matters.
*/
class Solution {
public:
	int numberOfPatterns(int m, int n) {
		int res = 0;
		vector<bool> visited(10, false);
		vector<vector<int>> keyboard(10, vector<int>(10, 0));//keyboard[i][j]表示从i跳转到j中间需要键值
		//根据规则初始化跳转矩阵的键值
		keyboard[1][3] = keyboard[3][1] = 2;
		keyboard[4][6] = keyboard[6][4] = 5;
		keyboard[7][9] = keyboard[9][7] = 8;
		keyboard[1][7] = keyboard[7][1] = 4;
		keyboard[2][8] = keyboard[8][2] = 5;
		keyboard[3][9] = keyboard[9][3] = 6;
		keyboard[1][9] = keyboard[9][1] = keyboard[3][7] = keyboard[7][3] = 5;
		//由对称性可得,1,3,7,9值相同;2,4,6,8值相同;5独自求值
		res += helper(1, 1, m, n, keyboard, visited) * 4;
		res += helper(2, 1, m, n, keyboard, visited) * 4;
		res += helper(5, 1, m, n, keyboard, visited);
		return res;
	}
	//从num开始深度遍历跳转矩阵keyboard
	//遍历1~9,找出可以直接到达的键和中间键已经被访问的键,添加到最终结果
	int helper(int num, int len, int m, int n, vector<vector<int>> &keyboard, vector<bool> visited)
	{
		int res = 0;
		if (len >= m)
			res++;
		++len;
		if (len > n)
			return res;
		visited[num] = true;
		for (int i = 1; i <= 9; ++i)
		{
			int mid = keyboard[num][i];
			if (!visited[i] && (mid == 0 || visited[mid]))
			{
				res += helper(i, len, m, n, keyboard, visited);
			}
		}
		visited[num] = false;
		return res;
	}
};
#endif