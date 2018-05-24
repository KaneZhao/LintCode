#ifndef C1367_H
#define C1367_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* �������
*
* ��һ��n x m�ľ��������ֵ1�����Ǹ�λ��վ��һ�����죬-1������ǽ��0�����ǿյء�
* �����������һ��n x m�������ÿһ���յص���������ľ���ľ��롣
* ע������
* ����n x m �ľ��� n <= 200��m <= 200��
* ��֤ÿ���յض��������ߵ�һ�����졣
* ����
* ���� mat =
* [
* [0,-1,0],
* [0,1,1],
* [0,0,0]
* ] ,����[[2,-1,1],[1,0,0],[2,1,1]]��
* ���쵽��������ľ��붼��0����2�����쵽�����յص��������������ʾ��
* ���� mat =
* [
* [0,-1,-1],
* [0,-1,1],
* [0,0,0]
* ],����[[5,-1,-1],[4,-1,0],[3,2,1]]��
* ���쵽5���յص��������������ʾ��
*/
class Solution {
public:
	/**
	* @param matrix : the martix
	* @return: the distance of grid to the police
	*/
	vector<vector<int>> policeDistance(vector<vector<int>> &matrix) {
		// Write your code here
		if (matrix.empty() || matrix[0].empty())
			return matrix;
		int rows = matrix.size();
		int cols = matrix[0].size();
		int cnt = rows*cols;
		map<int, int> visited;//����Ѿ����ʵ�λ������ֵ
		vector<vector<int>> dic{ { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
		//�ȴ�ž���λ�ú�ǽ��λ��
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (matrix[i][j] == 1)
				{
					visited[i*cols + j] = 0;
					matrix[i][j] = 0;
				}
				else if (matrix[i][j] == -1)
					visited[i*cols + j] = -1;
			}
		}
		//�Ӿ���λ�ÿ�ʼ��������Χλ�õ�ֵ
		int num = 0;
		while (visited.size() < cnt)
		{
			helper(matrix, dic, visited, num);
			++num;
		}
		return matrix;
	}
	//��visited��Ѱ������ֵΪnum��λ��,�����������������ĸ�λ��,����ֵΪnum+1
	void helper(vector<vector<int>> &matrix, vector<vector<int>> dic, map<int, int> &visited, int num)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (auto c : visited)
		{
			if (c.second == num)
			{
				for (auto t : dic)
				{
					int x = c.first / cols + t[0];
					int y = c.first % cols + t[1];
					if (x >= 0 && x < rows&&y >= 0 && y < cols && visited.find(x*cols+y)==visited.end())
					{
						matrix[x][y] = num + 1;
						visited[x*cols + y] = num + 1;
					}
				}
			}
		}
	}
};
#endif