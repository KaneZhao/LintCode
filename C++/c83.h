#ifndef C83_H
#define C83_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
* �䵥���� II
*
* ����3*n + 1 �������֣�������һ������֮������ÿ�����־��������Σ��ҵ�������֡�
* ����
* ���� [1,1,2,3,3,3,2,2,4,1] ������ 4
* ��ս
* һ�α������������Ķ���ռ临�Ӷ�
*/
class Solution {
public:
	int singleNumberII(vector<int> &A) {
		vector<int> nums(32, 0);
		int res = 0;
		//����nums���A��Ԫ���ڶ�����λÿ��λ���ϵ�����֮��,�����������ε�����
		for (auto c : A)
		{
			for (int i = 0; i < 32; ++i)
			{
				nums[i] = (nums[i] + ((c >> i) & 1))%3;
			}
		}
		//���õ��Ķ����ƽ��ת��Ϊʮ����
		for (int i = 0; i < 32; ++i)
		{
			res += nums[i] * pow(2, i);
		}
		return res;
	}
};
#endif