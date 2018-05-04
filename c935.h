#ifndef C935_H
#define C935_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �ѿ�����
* 
* ���ǲ��ö�ά����setList[][]��ʾ�������飬����setList[i]�е�ÿ��Ԫ�ض�Ϊ�������Ҳ���ͬ���󼯺�setList[0],setList[1],...,setList[setList.length - 1]�ĵѿ�������
* һ��أ�����A�ͼ���B�ĵѿ�����A��B = {(x,y)|x��A��y��B}��
* ע������
* 1 <= setList.length <= 5
* 1 <= setList[i].length <= 5
* ����
* ���� setList = [[1,2,3],[4],[5,6]]������ [[1,4,5],[1,4,6],[2,4,5],[2,4,6],[3,4,5],[3,4,6]]��
* ���ͣ�
* [1,2,3]��[4]��[5,6]�ĵѿ�����Ϊ[[1,4,5],[1,4,6],[2,4,5],[2,4,6],[3,4,5],[3,4,6]]
* ���� setList = [[1,2,3],[4]]������ [[1,4],[2,4],[3,4]]��
* ���ͣ�
* [1,2,3]��[4]�ĵѿ�����Ϊ[[1,4],[2,4],[3,4]]
*/
class Solution {
public:
	/**
	* @param setList: The input set list
	* @return: the cartesian product of the set list
	*/
	vector<vector<int>> getSet(vector<vector<int>> &setList) {
		// Write your code here
		vector<vector<int>> res;//������ս��
		vector<vector<int>> temp;//����м���
		for (auto c : setList[0])
			res.push_back({ c });
		//����setList[i],��ʱ�Ľ��Ϊres,�ѿ�����Ϊres�е�ÿ������ֱ����setList[i]��ÿ��Ԫ��
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