#ifndef C57_H
#define C57_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
/*
* ����֮��
*
* ����һ����n������������S����S���ҵ���������a, b, c���ҵ�����ʹ��a + b + c = 0����Ԫ�顣
* ע������
* ����Ԫ��(a, b, c)��Ҫ��a <= b <= c��
* ������ܰ����ظ�����Ԫ�顣
* ����
* ��S = {-1 0 1 2 -1 -4}, ����Ҫ���ص���Ԫ�鼯�ϵ��ǣ�
* (-1, 0, 1)
* (-1, -1, 2)
*/
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers) {
		// write your code here
		vector<vector<int>> res;
		set<vector<int>> set;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size() - 2; ++i)
		{
			for (int j = numbers.size() - 1; j>i + 1; --j)
			{
				for (int k = i + 1; k < j; ++k)
				{
					//����set�з�ֹ�ظ�
					if (numbers[i] + numbers[k] + numbers[j] == 0)
						set.insert({ numbers[i], numbers[k], numbers[j] });
				}
			}
		}
		for (auto it = set.begin(); it != set.end(); ++it)
			res.push_back(*it);
		return res;
	}
};
#endif