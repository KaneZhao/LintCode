#ifndef C898_H
#define C898_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �����1
*
* һ����ά���飬ÿһ�ж�ֻ��0��1��ǰ�沿����0����һ������1���ҵ���������������������ߵ�1���ڵ�������
* ע������
* ���������������������1000
* Ϊ��Լ��ʱ�临�Ӷȣ���ĳ��򽫻�����50000��
* ����
* ���� arr = [[0,0,0,1],[1,1,1,1]], ���� 0��
* ���ͣ�
* arr[1][0]Ϊ������������ߵ�1�������ڵ���Ϊ0��
* ���� arr = [[0,0,0,1],[0,1,1,1]], ���� 1��
* ���ͣ�
* arr[1][1]Ϊ������������ߵ�1�������ڵ���Ϊ1��
*/
class Solution {
public:
	/**
	* @param arr: The 2-dimension array
	* @return: Return the column the leftmost one is located
	*/
	int getColumn(vector<vector<int>> &arr) {
		// Write your code here
		if (arr.empty() || arr[0].empty())
			return 0;
		int row = arr.size();
		int col = arr[0].size();
		int pos = col - 1, temp = col - 1;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (arr[i][j] == 1)
				{
					temp = j;
					break;
				}
			}
			pos = minVal(pos, temp);
		}
		return pos;
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif