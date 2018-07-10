#ifndef C644_H
#define C644_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �� 1
*
* ����
* ���� �Ǹ� ���� num. ���������� 0 �� i �� num ���������� i ����Ҫ����������Ʊ�ʾ 1 �ĸ��������������ʽ����
* ����
* ���� num = 5 ����Ҫ���� [0,1,1,2,1,2].
* ��ս
* ʱ�临�Ӷ�Ϊ O(n * sizeof(integer))�Ľⷨ�������뵽, �������Ƿ���������Ե�ʱ�临�Ӷ� O(n)/����ֻ����һ����, �ռ临�Ӷ�ӦΪ O(n).
* ���ܰ��������������ս��? �������κ���Ƕ�ĺ���, ����C++ �е�__builtin_popcount ������κ����������еķ���
*/
class Solution {
public:
	/**
	* @param num: a non negative integer number
	* @return: an array represent the number of 1's in their binary
	*/
	vector<int> countBits(int num) {
		// write your code here
		if (num <= 0)
			return{0};
		vector<int> res(num + 1, 0);
		//���i������,����1�ĸ�����i-1����1�ĸ�����һ
		//���i��ż��,����1�ĸ�������i/2����1�ĸ���
		for (int i = 1; i <= num; ++i)
		{
			if (i % 2 != 0)
				res[i] = res[i - 1] + 1;
			else
				res[i] = res[i / 2];
		}
		return res;
	}
};
#endif