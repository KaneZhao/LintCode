#ifndef C665_H
#define C665_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ƽ�淶Χ��� -���ɱ����
*
* ��һ ��ά����,���������Ͻ� (row1, col1) �����½� (row2, col2) �����ľ�����Ԫ�غ�.
* ע������
* ����Լ�����󲻱�
* �Ժ��� sumRegion �ĵ��ô����кܶ��
* ����Լ��� row1 �� row2 ���� col1 �� col2
* ����
* ��������
* [
* [3, 0, 1, 4, 2],
* [5, 6, 3, 2, 1],
* [1, 2, 0, 1, 5],
* [4, 1, 0, 1, 7],
* [1, 0, 3, 0, 5]
* ]
* sumRegion(2, 1, 4, 3) -> 8
* sumRegion(1, 1, 2, 2) -> 11
* sumRegion(1, 2, 2, 4) -> 12
*/
class NumMatrix {
public:
	/*
	* @param matrix: a 2D matrix
	*/
	//��������vec[][]��vec[i][j]��ʾ��matrix[0][0]��matrix[i][j]�����������Ԫ��֮��
	NumMatrix(vector<vector<int>> matrix) {
		// do intialization if necessary
		vec = matrix;
		int row = vec.size(), col = vec[0].size();
		for (int j = 1; j < col; ++j)
		{
			vec[0][j] += vec[0][j - 1];
		}
		for (int i = 1; i < row; ++i)
		{
			vec[i][0] += vec[i - 1][0];
		}
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				vec[i][j] += vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1];
			}
		}
	}

	  /*
	  * @param row1: An integer
	  * @param col1: An integer
	  * @param row2: An integer
	  * @param col2: An integer
	  * @return: An integer
	  */
	  int sumRegion(int row1, int col1, int row2, int col2) {
		  // write your code here
		  int res = 0;
		  if (row1 == 0 && col1 == 0)
			  return vec[row2][col2];
		  else if (row1 == 0 && col1 != 0)
			  return vec[row2][col2] - vec[row2][col1 - 1];
		  else if (row1 != 0 && col1 == 0)
			  return vec[row2][col2] - vec[row1 - 1][col2];
		  else 
			  return vec[row2][col2] - vec[row2][col1 - 1] - vec[row1 - 1][col2] +
			  vec[row1 - 1][col1 - 1];

	  }
	  vector<vector<int>> vec;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/
#endif