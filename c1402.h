#ifndef C1402_H
#define C1402_H
#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;
/*
* �Ƽ�����
*
* ����
* ��n���˵�����������������user�����ҳ�user�������ʶ���ˡ�������user�����Ĺ�ͬ������������user�����ѣ�
* n <= 500��
* ���ѹ�ϵ���໥�ġ���b��������a�ĺ��������У�aһ��������b�ĺ��������У�
* ÿ���˵ĺ��ѹ�ϵ������ m ����m <= 3000��
* ����������˺�user�Ĺ�ͬ������Ŀһ����***��Ÿ�С***���Ǹ���Ϊ���������ʶ���ˡ�
* ���user������İ���˶�û�й�ͬ���ѣ����-1��
* ����
* ���� list = [[1,2,3],[0,4],[0,4],[0,4],[1,2,3]], user = 0, ���� 4��
* ���ͣ�
* 0��4�������ѣ�����������3����ͬ���ѡ�����4��0�������ʶ���ˡ�
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
		//res��Ų���user�����ѵ�����user��ͬ���ѵĸ���
		map<int, int> res;
		if (friends[user].empty())
			return -1;
		//dic[i]=1��ʾi��user������user������,dic[i]=0��ʾi����user������
		vector<int> dic(num, 0);
		dic[user] = 1;
		for (auto c : friends[user])
		{
			dic[c] = 1;
		}
		//�ҵ�����user���ѵ���
		for (int i = 0; i < num; ++i)
		{
			if (dic[i] == 0)
				res[i] = 0;
		}
		//����user�ĺ�����������res
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
		//�ҵ�����๲ͬ���ѵ���
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