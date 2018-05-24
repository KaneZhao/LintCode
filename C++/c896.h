#ifndef C896_H
#define C896_H
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*
* 质数乘积
*
* 给定一个无重复的质数数组arr，每个质数最多使用一次，求所有无重复的乘积并从小到大排序。
* 注意事项
* 2 <= |arr| <= 9
* 2 <= arr[i] <= 23
* 样例
* 给出 arr = [2,3], 返回 [6]。
* 解释：
* 2*3=6。
* 给出 arr = [2,3,5], 返回 [6,10,15,30]。
* 解释：
* 2*3=6, 2*5=10, 3*5=15, 2*3*5=30。
*/
class Solution {
public:
	/**
	* @param arr: The prime array
	* @return: Return the array of all of prime product
	*/
	vector<int> getPrimeProduct(vector<int> &arr) {
		// Write your code here
		vector<int> res;
		sort(arr.begin(), arr.end());
		//用arr的前两个元素初始化res
		res.push_back(arr[0] * arr[1]);
		//每增加一个元素arr[i],在res中添加arr中i位置之前的元素与arr[i]的乘积
		//再添加原res中所有元素与arr[i]的乘积
		for (int i = 2; i < arr.size(); ++i)
		{
			int len = res.size();
			for (int j = 0; j < i; ++j)
				res.push_back(arr[i] * arr[j]);
			for (int k = 0; k < len; ++k)
				res.push_back(arr[i] * res[k]);
		}
		sort(res.begin(), res.end());
		return res;
	}
};
#endif