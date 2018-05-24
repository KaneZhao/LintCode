#ifndef C785_H
#define C785_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ���Ȩֵ��·��
*
* ��һ��������λ��һ�� m �� n ����������Ͻǡ�
* ������ÿһʱ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǡ�ÿ����������һ������Ȩֵ��������ϣ�����ߵ����½ǵ�·��Ȩֵ�����
* ��������·��Ȩֵ���Ƕ��٣�
* ע������
* ����һ��n x m �ľ��󣬱�֤ n <= 200,m <= 200��
* ��Ŀ���ݱ�֤ 0 <= i <= n-1 , 0 <= j <= m-1, nums[i][j] <= 100000��
* ����
* ����
* [
* [1,2,3,4],
* [3,5,6,7],
* [9,10,1,2],
* [4,4,5,5]
* ]
* ������45��
* ���ͣ�
* �����Ͻǳ���������[4,7,6,5,10,9,4]�ߵ����½ǡ�Ȩֵ��Ϊ45��
*/
class Solution {
public:
	/**
	* @param nums:
	* @param k:
	* @return: nothing
	*/
	int MaxWeight(vector<vector<int>> &nums, int k) {
		// 
		if (nums.empty() || nums[0].empty())
			return 0;
		int row = nums.size(), col = nums[0].size();
		for (int i = col - 2; i >= 0; --i)
			nums[0][i] += nums[0][i + 1];
		for (int i = 1; i < row; ++i)
			nums[i][col - 1] += nums[i - 1][col - 1];
		for (int i = 1; i < row; ++i)
		{
			for (int j = col - 2; j >= 0; --j)
			{
				nums[i][j] += maxVal(nums[i - 1][j], nums[i][j + 1]);
			}
		}
		return nums[row - 1][0];
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif