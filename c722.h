#ifndef C722_H
#define C722_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ���������VI
*
* ����һ���������飬�ҳ����ֵ���������顣
* ʲô�����:https://en.wikipedia.org/wiki/Exclusive_or
* ע������
* Ԥ��ʱ�临�Ӷ�ΪO(n)
* ����
* ����nums = [1, 2, 3, 4],���� 7,������[3, 4]���������ֵ
* ����nums = [8, 1, 2, 12, 7, 6],���� 15,������[1, 2, 12]���������ֵ
* ����nums = [4, 6],���� 6,������[6]���������ֵ
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
	//�����ֵ���,�ӽڵ��ֵֻ��Ϊ0��1,��prefix�Ķ�������ʽ���뵽�ֵ�����
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
	//������prefix�������ֵ,����prefix�����Ƶ�ÿһλ,�Ӹ�λ��ʼ,����ѡ����
	//��λ�ϵ�����һ���Ľڵ�,��������ڣ���ѡ��ʣ�µĽڵ�
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