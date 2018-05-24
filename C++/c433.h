#ifndef C433_H
#define C433_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* ����ĸ���
*
* ��һ��01������ͬ�ĵ���ĸ�����
* 0������1�������������1���ڣ���ô������1����ͬһ����������ֻ������������Ϊ���ڡ�
* ����
* �ھ���
* [
* [1, 1, 0, 0, 0],
* [0, 1, 0, 0, 1],
* [0, 0, 0, 1, 1],
* [0, 0, 0, 0, 0],
* [0, 0, 0, 0, 1]
* ]
* ���� 3 ����.
*/
class Solution {
public:
	/*
	* @param grid: a boolean 2D matrix
	* @return: an integer
	*/
	int numIslands(vector<vector<bool>> &grid) {
		// write your code here
		if (grid.empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		int num = 0;
		map<int, int> visited;
		vector<vector<int>> dic{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };//�������λ��
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == 1 && visited.find(i*col + j) == visited.end())//��Ŀǰ�ǵ��죬�Ҳ�����֪�ĵ�������
				{
					num++;
					visit(grid, i, j, visited,dic);
				}
			}
		}
		return num;
	}
	void visit(vector<vector<bool>> &grid, int i, int j,map<int,int> &visited,vector<vector<int>> dic)
	{
		int row = grid.size();
		int col = grid[0].size();
		if (i < 0 || j < 0 || i >= row || j >= col)//��ֹ����Խ��
			return;
		if (visited[i*col + j] == 1||grid[i][j]==0)//�����Ѿ����ʹ��ĵ���ͷǵ��죬ֱ�ӷ���
			return;
		visited[i*col + j] = 1;
		for (auto c : dic)  //���㵱ǰ�������������ĸ�λ�õĵ���
		{
			int x = i + c[0];
			int y = j + c[1];
			visit(grid, x, y, visited,dic);//�ݹ�
		}
	}
};
#endif