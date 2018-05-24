#ifndef C698_H
#define C698_H
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<utility>
using namespace std;
/*
* ���������Ĳ�ֵ
* �� m ������, ÿһ�������Ϊ����. ��������Դ�������ͬ����������ѡ��������(ÿһ������ѡһ��)���Ҽ����ֵ. ���ǽ��������� a �� b ֮��Ĳ��Ϊ���ǵľ��Բ� |a - b|. ���������ȥ�ҵ����Ĳ�ֵ.
*
* ע������
* ÿһ�����������鳤������Ϊ 1. ������������Ϊ�յ�����
* m �����������������ĸ������� [2, 10000]��Χ��.
* m �����������е�����������[-10000, 10000]��Χ��.
*
* ����
* ��һ������ [[1,2,3], [4,5], [1,2,3]], ���� 4
* �������ֵ��һ�ַ�ʽ���ڵ�һ������������������ȡ 1, �ڵڶ���������ȡ 5.
*/
class Solution {
public:
	/*
	* @param : an array of arrays
	* @return: return the max distance among arrays
	*/
	int maxDiff(vector<vector<int>> &arrs) {
		// write your code here
		priority_queue<pair<int, int>> queMax;//ά������
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > queMin;//ά����С��
		//���д��(Ԫ��ֵ,����������ı��)
		for (int i = 0; i < arrs.size();++i)
		{
			if (!arrs[i].empty())
			{
				queMax.push(make_pair(arrs[i].back(), i));
				queMin.push(make_pair(arrs[i][0], i));
			}
		}
		//���Ѷ�����Ų�ͬ��ֱ�ӷ��ز�ֵ�����򣬼��������е����ֵ����С���еڶ�С��ֵ֮��Լ�
		//��С�ѵ���Сֵ�������еڶ���ֵ�ò��ȡ�������ֵ
		if (queMax.top().second != queMin.top().second)
		{
			return queMax.top().first - queMin.top().first;
		}
		else
		{
			int maxVal = queMax.top().first;
			queMax.pop();
			int minVal = queMin.top().first;
			queMin.pop();
			return Max(maxVal - queMin.top().first, queMax.top().first - minVal);
		}
	}
	int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif