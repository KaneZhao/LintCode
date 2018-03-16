#ifndef C109_H
#define C109_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ����������
*
* ����һ�����������Σ��ҵ��Ӷ������ײ�����С·���͡�ÿһ�������ƶ�������һ�е����������ϡ�
* ע������
* �����ֻ�ö���ռ临�Ӷ�O(n)����������ɿ��Ի�üӷ֣�����n�����������ε���������
* ����
* ���磬�����������������Σ�
* [
* [2],
* [3,4],
* [6,5,7],
* [4,1,8,3]
* ]
* �Ӷ����ײ�����С·����Ϊ11 ( 2 + 3 + 5 + 1 = 11)��
*/
class Solution {
public:
	/**
	* @param triangle: a list of lists of integers.
	* @return: An integer, minimum path sum.
	*/
	int minimumTotal(vector<vector<int>> &triangle) {
		// write your code here
		if (triangle.empty() || triangle[0].empty())
			return 0;
		int size = triangle.size();
		//�������εײ����ϼ���ÿ��λ�õ���С·����,�����丳ֵ��triangle[i][j]
		//triangle[i][j] = min{triangle[i+1][j],triangle[i+1][j+1]}+triangle[i][j]
		for (int i = size - 2; i >= 0; --i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				triangle[i][j] += minVal(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};

#endif