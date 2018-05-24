#ifndef C115_H
#define C115_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��ͬ��·�� II
*
* "��ͬ��·��" �ĸ������⣺
* ���ڿ������������ϰ�����������ж�������ͬ��·����
* �����е��ϰ��Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
* ע������
* m �� n ��������100
* ����
* ������ʾ��3x3����������һ���ϰ��
* [
* [0,0,0],
* [0,1,0],
* [0,0,0]
* ]
* һ����2����ͬ��·�������Ͻǵ����½ǡ�
*/
class Solution {
public:
	/**
	* @param obstacleGrid: A list of lists of integers
	* @return: An integer
	*/
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// write your code here
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> v(m, vector<int>(n));
		int flag1=0, flag2=0;
		//��ʼ��i,j=0�����,����obstacleGrid[i][0]����obstacleGrid[0][j]����Ԫ�ص�ֵ��Ϊ0
		for (int i = 0; i < m; ++i)
		{
			if (obstacleGrid[i][0] == 0&&flag1==0)
				v[i][0] = 1;
			else
			{
				flag1 = 1;
				v[i][0] = 0;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if (obstacleGrid[0][j] == 0 && flag2 == 0)
				v[0][j] = 1;
			else
			{
				flag2 = 1;
				v[0][j] = 0;
			}
		}
		//��obstacleGrid[i][j]=1,�޷�����v[i][j]ȡֵΪ0
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i - 1][j] == 0)
					v[i][j] += v[i - 1][j];
				if (obstacleGrid[i][j - 1] == 0)
					v[i][j] += v[i][j - 1];
				if (obstacleGrid[i][j] == 1)
					v[i][j] = 0;
			}
		}
		return v[m - 1][n - 1];
	}
};
#endif