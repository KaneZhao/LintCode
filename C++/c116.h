#ifndef C116_H
#define C116_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��Ծ��Ϸ
*
* ����һ���Ǹ��������飬�������λ������ĵ�һ��λ�á�������
* �����е�ÿ��Ԫ�ش��������Ǹ�λ�ÿ�����Ծ����󳤶ȡ���������
* �ж����Ƿ��ܵ�����������һ��λ�á�
* ����
* A = [2,3,1,1,4]������ true.
* A = [3,2,1,0,4]������ false.
*/
class Solution {
public:
	/**
	* @param A: A list of integers
	* @return: The boolean answer
	*/
	bool canJump(vector<int> A) {
		// write you code here
		int len = A.size();
		vector<bool> v(len, false);
		v[len - 1] = true;
		for (int i = len - 2; i >= 0; --i)
		{
			if (i + A[i] == len - 1)
				v[i] = true;
			for (int j = 0; j <= A[i]; ++j)
			{
				if (i + j <= len - 1 && v[i + j] == true)
				{
					v[i] = true;
					break;
				}
			}
		}
		return v[0];
	}
};
#endif