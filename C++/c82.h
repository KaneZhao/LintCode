#ifndef C82_H
#define C82_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �䵥����
*
* ����2*n + 1 �������֣�������һ������֮������ÿ�����־��������Σ��ҵ�������֡�
* ����
* ���� [1,2,2,1,3,4,3]������ 4
* ��ս
* һ�α������������Ķ���ռ临�Ӷ�
*/
class Solution {
public:
	/**
	* @param A: An integer array
	* @return: An integer
	*/
	int singleNumber(vector<int> &A) {
		// write your code here
		int res = A[0];
		//����a^b^b=a
		for (int i = 1; i < A.size(); ++i)
			res ^= A[i];
		return res;
	}
};
#endif