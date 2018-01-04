#ifndef C722_H
#define C722_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最大子数组VI
*
* 给出一个整数数组，找出异或值最大的子数组。
* 什么是异或:https://en.wikipedia.org/wiki/Exclusive_or
* 注意事项
* 预期时间复杂度为O(n)
* 样例
* 给出nums = [1, 2, 3, 4],返回 7,子数组[3, 4]有最大的异或值
* 给出nums = [8, 1, 2, 12, 7, 6],返回 15,子数组[1, 2, 12]有最大的异或值
* 给出nums = [4, 6],返回 6,子数组[6]有最大的异或值
*/
class TrieNode{
public:
	int val;
	TrieNode *child[2];
	TrieNode(){
		this->val = 0;
		this->child[0] = this->child[1] = NULL;
	}
};
class Solution {
public:
	/*
	* @param : the array
	* @return: the max xor sum of the subarray in a given array
	*/
	int maxXorSubarray(vector<int> &nums) {
		// write code here
		TrieNode *root = new TrieNode();
		insert(root, 0);
		int res = INT_MIN, prefix = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			prefix = prefix^nums[i];
			insert(root, prefix);
			res = maxVal(res, query(root, prefix));
		}
		return res;
	}
	//构建字典树,子节点的值只能为0或1,将prefix的二进制形式插入到字典树中
	void insert(TrieNode *root, int prefix)
	{
		TrieNode *node = root;
		for (int i = 31; i >= 0; --i)
		{
			bool value = prefix & (1 << i);
			if (node->child[value] == NULL)
				node->child[value] = new TrieNode();
			node = node->child[value];
		}
		node->val = prefix;
	}
	//查找与prefix异或的最大值,遍历prefix二进制的每一位,从高位开始,优先选择与
	//此位上的数不一样的节点,如果不存在，就选择剩下的节点
	int query(TrieNode *root, int prefix)
	{
		TrieNode *node = root;
		for (int i = 31; i >= 0; --i)
		{
			bool value = prefix & (1 << i);
			if (node->child[1 - value] != NULL)
				node = node->child[1 - value];
			else
				node = node->child[value];
		}
		return prefix ^ (node->val);
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif