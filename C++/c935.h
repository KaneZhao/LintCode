#ifndef C935_H
#define C935_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 笛卡尔积
* 
* 我们采用二维数组setList[][]表示集合数组，其中setList[i]中的每个元素都为整数，且不相同。求集合setList[0],setList[1],...,setList[setList.length - 1]的笛卡尔积。
* 一般地，集合A和集合B的笛卡尔积A×B = {(x,y)|x∈A∧y∈B}。
* 注意事项
* 1 <= setList.length <= 5
* 1 <= setList[i].length <= 5
* 样例
* 给出 setList = [[1,2,3],[4],[5,6]]，返回 [[1,4,5],[1,4,6],[2,4,5],[2,4,6],[3,4,5],[3,4,6]]。
* 解释：
* [1,2,3]和[4]和[5,6]的笛卡尔积为[[1,4,5],[1,4,6],[2,4,5],[2,4,6],[3,4,5],[3,4,6]]
* 给出 setList = [[1,2,3],[4]]，返回 [[1,4],[2,4],[3,4]]。
* 解释：
* [1,2,3]和[4]的笛卡尔积为[[1,4],[2,4],[3,4]]
*/
class Solution {
public:
	/**
	* @param setList: The input set list
	* @return: the cartesian product of the set list
	*/
	vector<vector<int>> getSet(vector<vector<int>> &setList) {
		// Write your code here
		vector<vector<int>> res;//存放最终结果
		vector<vector<int>> temp;//存放中间结果
		for (auto c : setList[0])
			res.push_back({ c });
		//对于setList[i],此时的结果为res,笛卡尔积为res中的每个数组分别添加setList[i]的每个元素
		for (int i = 1; i < setList.size(); ++i)
		{
			for (auto c : res)
			{
				for (auto t: setList[i])
				{
					vector<int> v = c;
					v.push_back(t);
					temp.push_back(v);
				}
			}
			res = temp;
			temp.clear();
		}
		return res;
	}
};
#endif