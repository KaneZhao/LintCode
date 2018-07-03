#ifndef C17_H
#define C17_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* �Ӽ�
*
* ����
* ����һ������ͬ�����ļ��ϣ����������е��Ӽ�
* �Ӽ��е�Ԫ�����б����Ƿǽ���ģ��⼯���벻�����ظ����Ӽ�
* ����
* ��� S = [1,2,3]�������µĽ⣺
* [
* [3],
* [1],
* [2],
* [1,2,3],
* [1,3],
* [2,3],
* [1,2],
* []
* ]
*/
bool cmp(const int a, const int b)
{
	return a > b;
}
class Solution {
public:
	/**
	* @param nums: A set of numbers
	* @return: A list of lists
	*/
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return{ {} };
		//������������
		sort(nums.begin(), nums.end(), cmp);
		//������β����ʼ�������
		//�µ�res��ԭres�ټ���ÿ��resԪ�ؼ���nums��β��
		while (!nums.empty())
		{
			if (res.empty())
			{
				res.push_back({ nums.back() });
				res.push_back({});
			}
			else
			{
				int len = res.size();
				for (int i = 0; i < len; ++i)
				{
					vector<int> temp = res[i];
					temp.push_back(nums.back());
					res.push_back(temp);
				}
			}
			nums.pop_back();
		}
		return res;
	}
	vector<vector<int>> res;
};
#endif