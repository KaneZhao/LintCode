#ifndef C831_H
#define C831_H
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
using namespace std;
/*
* ����֮�� II
*
* ����n�������з���x^2+y^2+z^2 = n�� x, y, z �ķ�������(x, y, zΪ�Ǹ�����)
* ע������
* n <= 1000000
* x,y,z����(x<=y<=z)��ֻҪѡ���������������ͬ����ͬһ�ַ�����
* ����
* ���� n = 0������ 1��
* ���ͣ�
* �� x = 0 , y = 0, z = 0ʱ��ʽ������
* ���� n = 1������ 1��
* ���ͣ�
* ������һ��Ϊ1��ʣ������Ϊ0��һ����1�ַ�����
*/
class Solution {
public:
	/**
	* @param n: an integer
	* @return: the number of solutions
	*/
	int threeSum2(int n) {
		// Write your code here
		vector<int> nums;
		set<vector<int>> set;
		//�ҵ�0-n֮ǰ����ȫƽ��������������nums
		for (int i = 0; i <= sqrt(n); ++i)
			nums.push_back(i*i);
		int size = nums.size();
		//������֮��
		for (int i = 0; i < size; ++i)
		{
			for (int j = size - 1; j >= i; --j)
			{
				for (int k = i; k <= j; ++k)
				{
					if (nums[i] + nums[k] + nums[j] == n)
						set.insert({ nums[i], nums[k], nums[j] });
				}
			}
		}
		return set.size();
	}
};
#endif