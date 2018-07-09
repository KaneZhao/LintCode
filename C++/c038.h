#ifndef C38_H
#define C38_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ������ά���� II
*
* ����
* д��һ����Ч���㷨������m��n�����е�ֵ���������ֵ���ֵĴ�����
* �����������������ԣ�
* ÿ���е�����������������ġ�
* ÿһ�е��������ϵ���������ġ�
* ��ÿһ�л�ÿһ����û���ظ���������
* ����
* �������о���
* [
* [1, 3, 5, 7],
* [2, 4, 7, 8],
* [3, 5, 9, 10]
* ]
* ����target = 3������ 2
* ��ս
* Ҫ��O(m+n) ʱ�临�ӶȺ�O(1) ����ռ�
*/
class Solution {
public:
	/**
	* @param matrix: A list of lists of integers
	* @param target: An integer you want to search in matrix
	* @return: An integer indicate the total occurrence of target in the given matrix
	*/
	int searchMatrix(vector<vector<int>> &matrix, int target) {
		// write your code here
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int i = 0, j = matrix[0].size() - 1;
		int cnt = 0;
		//ÿ�����������Ͻǵ�Ԫ�غ�target�Ƚ�
		//����matrix[i][j],matrix[i][j]>target����ǰһ��,matrix[i][j]=<target������һ��
		while (i <matrix.size() && j >= 0)
		{
			if (matrix[i][j] > target)
				j--;
			else if (matrix[i][j] == target)
			{
				i++;
				cnt++;
			}
			else
				i++;
		}
		return cnt;
	}
};
#endif