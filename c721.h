#ifndef C721_H
#define C721_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��һ��ϡ����
*
* һ������ϡ�������������� �����Ʊ�ʾ ��û�����ڵ� 1������һ�� n ���ҳ����ڻ���� n ����С��ϡ������
* eg. 5 (�����Ʊ�ʾΪ 101)��ϡ���������� 6 (�����Ʊ�ʾΪ 110 ������ϡ����
* ����
* ���� n = 6,���� 8��һ��ϡ������8
* ���� n = 4,���� 4��һ��ϡ������4
* ���� n = 38,���� 40��һ��ϡ������40
* ���� n = 44,���� 64��һ��ϡ������64
*/


/*
class Solution {
public:
	int nextSparseNum(int x) {
		// write your code here
		if (isSpareNum(x))
			return x;
		int n = x;
		int len = 0;
		//��ȡx�Ķ����Ƴ���
		for (; n; n >>= 1)
			++len;
		//��xĩβ��i������0,�ټ���2��i�η�
		for (int i = 0; i <= len; ++i)
		{
			int res = (x&INT_MAX << i) + 1<<i;
			if (isSpareNum(res))
				return res;
		}
	}
	//�ж��Ƿ�Ϊϡ����
	bool isSpareNum(int x)
	{
		int num = x;
		bool flag = false;
		while (num != 0)
		{
			if (flag)
			{
				if (num & 1)
					return false;
				else
					flag = false;
			}
			else
			{
				if (num & 1)
					flag = true;
			}
			num = num >> 1;
		}
		return true;
	}
};
*/
class Solution {
public:
	/*
	* @param : a number
	* @return: return the next sparse number behind x
	*/
	int nextSparseNum(int x) {
		// write your code here
		vector<int> vec;//���x�����Ƶ�ÿһλ
		while (x != 0)
		{
			vec.push_back(x & 1);
			x >>= 1;
		}
		//���ǵ�������ܻ��һλ
		vec.push_back(0);
		int len = vec.size();
		int pos = 0;
		//��x�Ķ�������ʽ���뵽�����У���ʼ��pos=0������iλ�ó�������������11�ҵ�����������1����ѵ���������1��vec[i+1]=1����֮��vec��pos��iλ�þ���Ϊ0��������pos=i+1��
		for (int i = 1; i < len - 1; ++i)
		{
			if (vec[i] == 1 && vec[i - 1] == 1 && vec[i + 1] != 1)
			{
				vec[i + 1] = 1;
				for (int j = i; j >= pos; j--)
					vec[j] = 0;
				pos = i + 1;
			}
		}
		int res = 0;
		for (int i = 0; i < len; ++i)
			res += vec[i] * (1 << i);
		return res;
	}
};
#endif