#ifndef C721_H
#define C721_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 下一个稀疏数
*
* 一个数是稀疏数如果这个数的 二进制表示 中没有相邻的 1，给出一个 n ，找出大于或等于 n 的最小的稀疏数。
* eg. 5 (二进制表示为 101)是稀疏数，但是 6 (二进制表示为 110 ）不是稀疏数
* 样例
* 给出 n = 6,返回 8下一个稀疏数是8
* 给出 n = 4,返回 4下一个稀疏数是4
* 给出 n = 38,返回 40下一个稀疏数是40
* 给出 n = 44,返回 64下一个稀疏数是64
*/


/*
class Solution {
public:
	int nextSparseNum(int x) {
		// write your code here
		if (isSpareNum(x))
			return x;
		int n = x;
		int len = 0;
		//获取x的二进制长度
		for (; n; n >>= 1)
			++len;
		//把x末尾的i个数置0,再加上2的i次方
		for (int i = 0; i <= len; ++i)
		{
			int res = (x&INT_MAX << i) + 1<<i;
			if (isSpareNum(res))
				return res;
		}
	}
	//判断是否为稀疏数
	bool isSpareNum(int x)
	{
		int num = x;
		bool flag = false;
		while (num != 0)
		{
			if (flag)
			{
				if (num & 1)
					return false;
				else
					flag = false;
			}
			else
			{
				if (num & 1)
					flag = true;
			}
			num = num >> 1;
		}
		return true;
	}
};
*/
class Solution {
public:
	/*
	* @param : a number
	* @return: return the next sparse number behind x
	*/
	int nextSparseNum(int x) {
		// write your code here
		vector<int> vec;//存放x二进制的每一位
		while (x != 0)
		{
			vec.push_back(x & 1);
			x >>= 1;
		}
		//考虑到结果可能会多一位
		vec.push_back(0);
		int len = vec.size();
		int pos = 0;
		//将x的二进制形式存入到数组中，初始化pos=0，若在i位置出现两个连续的11且第三个数不是1。则把第三个数置1（vec[i+1]=1），之后将vec中pos到i位置均置为0，并更新pos=i+1。
		for (int i = 1; i < len - 1; ++i)
		{
			if (vec[i] == 1 && vec[i - 1] == 1 && vec[i + 1] != 1)
			{
				vec[i + 1] = 1;
				for (int j = i; j >= pos; j--)
					vec[j] = 0;
				pos = i + 1;
			}
		}
		int res = 0;
		for (int i = 0; i < len; ++i)
			res += vec[i] * (1 << i);
		return res;
	}
};
#endif