#ifndef C84_H
#define C84_H
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
/*
* �䵥���� III
*
* ����2*n + 2�������֣���������������֮������ÿ�����־��������Σ��ҵ����������֡�
* ����
* ���� [1,2,2,3,4,4,5,3]������ 1��5
* ��ս
* O(n)ʱ�临�Ӷȣ�O(1)�Ķ���ռ临�Ӷ�
*/
class Solution {
public:
	vector<int> singleNumberIII(vector<int> &A) {
		// write your code here
		vector<int> nums(32, 0);
		vector<int> vec;
		int res = 0;
		int pos = 0;
		int num1 = 0, num2 = 0;
		//nums��ŵĽ��Ϊnum1^num2,��ΪXor
		for (auto c : A)
		{
			for (int i = 0; i < 32; ++i)
			{
				nums[i] = (nums[i] + ((c >> i) & 1)) % 2;
			}
		}
		//�ҵ�Xor�����λ��1����λ��pos
		for (int i = 0; i < 32; ++i)
		{
			if (nums[i] == 1)
			{
				pos = i;
				break;
			}
		}
		//����λ��pos�Ƿ�Ϊ1,��A�ֳ�����,�ֱ������䵥����
		for (auto c : A)
		{
			if ((c >> pos) & 1 == 1)
				num1 ^= c;
			else
				num2 ^= c;
		}
		vec.push_back(num1);
		vec.push_back(num2);
		return vec;
	}
};
#endif