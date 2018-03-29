#ifndef C114_H
#define C114_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��ͬ��·��
*
* ��һ�������˵�λ��һ�� m �� n ���������Ͻǡ�
* ������ÿһʱ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǡ�
* ���ж�������ͬ��·����
* ע������
* n��m��������100
* ����
* ���� m = 3 �� n = 3, ���� 6.
* ���� m = 4 �� n = 5, ���� 35.
*/
class Solution {
public:
	/**
	* @param n, m: positive integer (1 <= n ,m <= 100)
	* @return an integer
	*/
	int uniquePaths(int m, int n) {
		// wirte your code here
		vector<vector<int>> v(m, vector<int>(n));//v[i][j]��ʾ��v[0][0]��v[i][j]��·����
		for (int i = 0; i < m; ++i)
			v[i][0] = 1;
		for (int j = 0; j < n; ++j)
			v[0][j] = 1;
		//����ֻ�����»�������
		//v[i][j]ֻ�ܴ�v[i-1][j]��v[i][j-1]����,��ֵΪ����λ��·����֮��
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m-1][n - 1];
	}
};

#endif