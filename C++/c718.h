#ifndef C718_H
#define C718_H
#include<iostream>
#include<string>
using namespace std;
/*
* �ظ��Ӵ�
*
* дһ������, ��һ���� N ���ַ����ɵ��ַ��� A��һ���� M ���ַ����ɵ��ַ��� B, ���� A �����ظ��Ĵ�����ʹ�� B ���ظ��ַ������Ӵ�.��� B ������Ϊ�ظ��ַ������Ӵ�, �򷵻� -1.
*
* ע������
* Assume that 0 <= N <= 1000, 1 <= M <= 1000
*
* ����
* ���� A = abcd, B = cdabcdab
* ��ķ�����Ҫ���� 3, ��Ϊ���ظ��ַ��� A 3��֮�����ǵõ����ִ� abcdabcdabcd. �ַ���B������ַ�����һ���Ӵ�.
*/
class Solution {
public:
	/*
	* @param : string A to be repeated
	* @param : string B
	* @return: the minimum number of times A has to be repeated
	*/
	int repeatedString(string &A, string &B) {
		// write your code here
		if (A.empty())
			return -1;
		int cnt = 0;
		while (B.find(A) != string::npos)//����ɾ��B�е�A,������
		{
			B.erase(B.find(A), A.size());
			cnt++;
		}
		//��ɾ��֮��BΪ�գ���ֱ�ӷ���cnt��������B��A���Ӵ�������cnt + 1��
		//������B��AA���Ӵ�������cnt + 2�����򷵻� - 1
		if (B.empty())
			return cnt;
		if (A.find(B)!=string::npos)
			return cnt + 1;
		else
		{
			A += A;
			if (A.find(B) != string::npos)
				return cnt + 2;
			else
				return -1;
		}
	}
};
#endif