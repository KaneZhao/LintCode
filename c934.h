#ifndef C934_H
#define C934_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��������
*
* n��Կ�ף����1-n����m���������1-m���������ĺ����ܹ���Կ�׵ĺ���������ʱ�򣬸����Ϳ��Ա���/�رա�������е���������ס��״̬��Ȼ�������е�Կ��ȥ�����е����������м���������Ǵ򿪵ġ�
* ע������
* 1 <= m, n <= 10^5
* ����
* ���� n = 1, m = 1, ���� 1��
* ���ͣ�
* ���Ϊ1����������
* ���� n = 2, m = 5, ����3��
* ���ͣ�
* ���Ϊ1,3,5����������
*/
class Solution {
public:
	/**
	* @param n: the number of keys
	* @param m: the number of locks
	* @return: the numbers of open locks
	*/
	int unlock(int n, int m) {
		// Write your code here
		int res = 0;
		vector<int> nums(m + 1, 0);
		//����1~n�ҵ�С��m�ҿ�����������i*j,��nums[i*j]+1
		for (int i = 1; i <= n; ++i)
		{
			int j = 1;
			while (i*j <= m)
			{
				nums[i*j]++;
				++j;
			}
		}
		//ֻ���ڽ��п����������ε������,��Ӧ��ŵ������Ǵ򿪵�
		for (auto c : nums)
		{
			if (c % 2 == 1)
				res++;
		}
		return res;
	}
};
#endif