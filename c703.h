#ifndef C703_H
#define C703_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
�۵�����

��һ������Ϊ n ������ nums ��һ������Ϊ k ������ req, ����Ҫ����Ҫ���۵����飬������۵��Ľ��
1.��� req[i] = 0 ��ζ����Ӧ�ô������۵�, ����:

1 2 3 4 5 6 7 8  ==>   4 3 2 1
5 6 7 8
2.��� req[i] = 1 ��ζ����Ӧ�ô��������۵�, ����:

1 2 3 4 5 6 7 8  ==>   8 7 6 5
1 2 3 4
���������:

�������۵�
4 3 2 1  ==>  6 5
5 6 7 8       3 4
2 1
7 8


���ҵ����۵�
6 5  ==>   8
3 4        1
2 1        4
7 8        5
6
3
2
7
ע������

n Ϊ 2 ����
k ��ָ��.(���� n = 2^3 = 8��k = 3)

����
�������� nums = [1, 2, 3, 4, 5, 6, 7, 8] �� ���� req = [0, 0, 1] ԭ�ظı�Ԫ��λ��Ϊ [8, 1, 4, 5, 6, 3, 2, 7]
*/
class Solution {
public:
	/*
	* @param : the original array
	* @param : the direction each time
	* @return: the final folded array
	*/
	vector<int> folding(vector<int> &nums, vector<int> &req) {
		// write your code here
		int len = req.size();
		for (int i = 0; i < len; ++i)
		{
			if (req[i] == 0)
				left(nums, (int)pow(2, i));
			else
				right(nums, (int)pow(2, i));
		}
		return nums;
	}
	//���������۵����������ǰ�벿�ַ��򣬸��ݳ���len�Ĵ�С����ǰ�벿�����벿�ְ������˳����ϳ��µ����顣 
	void left(vector<int> &nums, int len)
	{
		vector<int> res;
		int n = nums.size() / (len*2);
		reverse(nums.begin(), nums.begin() + nums.size()/2);
		for (int i = 0; i < n; ++i)
		{
			res.insert(res.end(), nums.begin() + i*len, nums.begin() + i*len + len);
			res.insert(res.end(), nums.begin() + i*len + nums.size()/2, nums.begin() + i*len + len + nums.size()/2);
		}
		nums = res;
	}
	//���������۵���������ĺ�벿�ַ��򣬸��ݳ���len�Ĵ�С������벿����ǰ�벿�ְ������˳����ϳ��µ����顣
	void right(vector<int> &nums, int len)
	{
		vector<int> res;
		int n = nums.size() / (len * 2);
		reverse(nums.begin() + nums.size() / 2, nums.end());
		for (int i = 0; i < n; ++i)
		{		
			res.insert(res.end(), nums.begin() + i*len + nums.size() / 2, nums.begin() + i*len + len + nums.size() / 2);
			res.insert(res.end(), nums.begin() + i*len, nums.begin() + i*len + len);
		}
		nums = res;
	}
};
#endif