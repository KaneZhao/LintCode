#ifndef C388_H
#define C388_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 第k个排列
*
* 描述
* 给定 n 和 k，求123..n组成的排列中的第 k 个排列。
* 1 ≤ n ≤ 9
* 样例
* 对于 n = 3, 所有的排列如下：
* 123
* 132
* 213
* 231
* 312
* 321
* 如果 k = 4, 第4个排列为，231.
* 挑战
* O(n*k) in time complexity is easy, can you do it in O(n^2) or less?
*/
class Solution {
public:
	/*
	* @param n: n
	* @param k: the k th permutation
	* @return: return the k-th permutation
	*/
	string getPermutation(int n, int k) {
		// write your code here
		string res;
		if (n <= 0 || k <= 0)
			return res;
		vector<char> nums;//存放初始数组
		int m = 1;
		//m表示以nums中任一元素开头的排列数
		for (int i = 1; i < n; ++i)
			m *= i;
		for (int i = 0; i <= n; ++i)
			nums.push_back(i + '0');
		//num为元素在nums中的位置,添加num对应的字符
		//更新k与m的值
		for (int i = 1; i < n; ++i)
		{
			int num = (k - 1) / m + 1;
			if (k == 0)
				num = nums.size() - 1;
			res += nums[num];
			k %= m;
			m /= n - i;
			nums.erase(nums.begin() + num);
		}
		res += nums[1];
		return res;
	}
};
#endif