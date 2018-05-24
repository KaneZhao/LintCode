#ifndef C163_H
#define C163_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 不同的二叉查找树
*
* 给出 n，问由 1...n 为节点组成的不同的二叉查找树有多少种？
* 样例
* 给出n = 3，有5种不同形态的二叉查找树：
* 1           3    3       2      1
*  \         /    /       / \      \
*   3      2     1       1   3      2
*  /      /       \                  \
* 2      1         2                  3
*/
class Solution {
public:
	/**
	* @paramn n: An integer
	* @return: An integer
	*/
	int numTrees(int n) {
		// write your code here
		if (n < 0)
			return 0;
		/*用f(n)来表示产生二叉树的种类，易得f(0)=0(边界条件)，f(1)=1，f(2)=2； 
		对于f(3)，分三种情况：
		当1为根，2，3在1的右子树，为f(2);
		当2为根，1，3分别为左右子树，为f(1);
		当3为根，1，2在3的左子树，为f(2)；
		f(3) = f(2) + f(1) + f(2)
		故f(i)=f(k-1)*f(i-k)
		*/
		vector<int> v(n + 1);
		v[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int k = 1; k <= i; ++k)
			{
				v[i] += v[k - 1] * v[i - k];
			}
		}
		return v[n];
	}
};
#endif