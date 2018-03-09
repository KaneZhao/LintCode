#ifndef C56_H
#define C56_H
#include<vector>
#include<iostream>
#include<map>
using namespace std;
/*
* ����֮��
*
* ��һ���������飬�ҵ�������ʹ�����ǵĺ͵���һ���������� target��
* ����Ҫʵ�ֵĺ���twoSum��Ҫ���������������±�, ���ҵ�һ���±�С�ڵڶ����±ꡣע�������±�ķ�Χ�� 0 �� n-1��
* ע������
* ����Լ���ֻ��һ��𰸡�
* ����
* ���� numbers = [2, 7, 11, 15], target = 9, ���� [0, 1].
*/
class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		vector<int> res{-1,-1};
		map<int, int> map;//���Ԫ�غ��±�
		//��������,��Map�д�����Ԫ��֮��Ϊtarget����,�������res��
		//��û��,��Ԫ�غ��±����map
		for (int i = 0; i < nums.size(); ++i)
		{
			if (map.find(target - nums[i]) != map.end())
			{
				res[0] = map[target - nums[i]];
				res[1] = i;
				break;
			}
			map[nums[i]] = i;
		}
		return res;
	}
};
#endif