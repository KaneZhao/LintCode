#ifndef C706_H
#define C706_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 给了一个二进制显示时间的手表和一个非负整数 n, n 代表在给定时间表上 1 的数量, 返回所有可能的时间
*
* 注意事项
* 输出的顺序没有要求.
* 小时不能包含前导零, 比如 "01:00" 是不允许的, 应该为 "1:00".
* 分钟必须由两位数组成, 可能包含前导零, 比如 "10:2" 是无效的, 应该为 "10:02".
*
* 样例
* 给出 n = 1
* 返回 ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/
class Solution {
public:
	/*
	* @param : the number of "1"s on a given timetable
	* @return: all possible time
	*/
	vector<string> binaryTime(int num) {
		// Write your code here
		vector<string> res;
		//num在0-8之间有意义
		if (num == 0)
			return{ "0:00" };
		if (num >= 9)
			return res;
		vector<vector<int>> dic(6, vector<int>());//存储包含0-5个1的数字
		for (int i = 0; i < 60; ++i)
			dic[countOne(i)].push_back(i);
		//从小时部分开始处理
		for (int i = 0; i <= 3; ++i)
		{
			//需要符合的一些条件
			if (num - i <= 5 && num - i >= 0)
			{
				//处理分钟部分
				for (auto c : dic[i])
				{
					if (c < 12)
					{
						for (auto t : dic[num - i])
						{
							string str;
							if (t >= 10)
								 str = to_string(c) + ":" + to_string(t);
							else
								 str = to_string(c) + ":0" + to_string(t);
							res.push_back(str);
						}
					}
				}
			}
		}
		return res;
	}
	//计算数字中包含1的个数
	int countOne(int num)
	{
		int cnt = 0;
		while (num != 0)
		{
			if (num & 1 != 0)
				cnt++;
			num = num >> 1;
		}
		return cnt;
	}
};
#endif