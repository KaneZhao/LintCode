#ifndef C1402_H
#define C1402_H
#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;
/*
* 推荐朋友
*
* 描述
* 给n个人的朋友名单，告诉你user，请找出user最可能认识的人。（他和user有最多的共同好友且他不是user的朋友）
* n <= 500。
* 好友关系是相互的。（b若出现在a的好友名单中，a一定出现在b的好友名单中）
* 每个人的好友关系不超过 m 条，m <= 3000。
* 如果有两个人和user的共同好友数目一样，***编号更小***的那个认为是最可能认识的人。
* 如果user和所有陌生人都没有共同好友，输出-1。
* 样例
* 给出 list = [[1,2,3],[0,4],[0,4],[0,4],[1,2,3]], user = 0, 返回 4。
* 解释：
* 0和4不是朋友，并且他们有3个共同好友。所以4是0最可能认识的人。
*/
class Solution {
public:
	/**
	* @param friends: people's friends
	* @param user: the user's id
	* @return: the person who most likely to know
	*/
	int recommendFriends(vector<vector<int>> &friends, int user) {
		// Write your code here 
		if (friends.empty())
			return -1;
		int num = friends.size();
		//res存放不是user的朋友的人与user共同好友的个数
		map<int, int> res;
		if (friends[user].empty())
			return -1;
		//dic[i]=1表示i是user或者是user的朋友,dic[i]=0表示i不是user的朋友
		vector<int> dic(num, 0);
		dic[user] = 1;
		for (auto c : friends[user])
		{
			dic[c] = 1;
		}
		//找到不是user好友的人
		for (int i = 0; i < num; ++i)
		{
			if (dic[i] == 0)
				res[i] = 0;
		}
		//根据user的好友名单更新res
		for (auto c : friends[user])
		{
			for (auto t : friends[c])
			{
				if (res.find(t) != res.end())
					res[t]++;
			}
		}
		int Max = 0;
		int person = -1;
		//找到有最多共同好友的人
		for (auto c : res)
		{
			if (c.second > Max)
			{
				Max = c.second;
				person = c.first;
			}
		}
		return person;
	}
};
#endif