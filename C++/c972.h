#ifndef C972_H
#define C972_H
#include<iostream>
#include<vector>
using namespace std;
/*
������Ϣ

��һ����˾����Ա��Ϣ����i���˴�����Ϣ��ʱ�仨��Ϊt[i]����������Ϊlist[i]����ĳ�˽ӵ���Ϣ���������ϴ��ݸ���������������0��������CEO������CEO������һ����Ϣ������ȥ���ʹ�˾���������˶��յ���Ϣ��ʱ���Ƕ��٣�

ע������
��˾����Ϊn��n <= 1000��
ÿ���˿����ж����������ֻ����һ���ϼ���
ʱ��t[i] <= 10000��
����Ϊ-1����û��������

����
���� t = [1,2,3], list = [[1,2],[-1],[-1]], ���� 1��

���ͣ�
��Ϣ��CEO��ʼ���ݣ���1�š�2������ʱʱ��Ϊ1����ʱ��˾�����˶��ӵ���Ϣ�ˡ�
���� t = [1,2,1,4,5], list = [[1,2],[3,4],[-1],[-1],[-1]], ���� 3��

���ͣ�
��Ϣ��CEO��ʼ���ݣ���1��2������ʱʱ��Ϊ1����3������ʱ��Ϊ3����Ϣ��2���ݵ�4 �� ��1���ݵ�4���죬���Դ��ݵ�4��ʱ��Ϊ2�������ʱ��Ϊ3ʱ�����˶��յ���Ϣ�ˡ�
*/
class Solution {
public:
	/**
	* @param t: the time of each employee to pass a meeage
	* @param subordinate: the subordinate of each employee
	* @return: the time of the last staff recieve the message
	*/
	int deliverMessage(vector<int> &t, vector<vector<int>> &subordinate) {
		// Write your code here
		if (t.empty() || subordinate.empty())
			return 0;
		int len = t.size();
		vector<int> staff(len, 0);//staff[i]��ʾ��Ϣ���ݵ�iԱ������Ҫ��ʱ��
		helper(0, staff, t, subordinate);
		int res = 0;
		for (auto c : staff)
		{
			res = c > res ? c : res;
		}
		return res;
	}
	void helper(int start, vector<int> &staff, vector<int> &t, vector<vector<int>> &subordinate)
	{
		for (int i = 0; i < subordinate[start].size(); ++i)
		{
			//����Ա��i��ÿ������,�յ���Ϣ��ʱ��ΪԱ��i�յ���Ϣ��ʱ��+��Ϣ����ʱ��
			if (subordinate[start][i] != -1)
			{
				staff[subordinate[start][i]] = staff[start] + t[start];
				helper(subordinate[start][i], staff, t, subordinate);
			}
			else
				return;
		}
	}
};
#endif