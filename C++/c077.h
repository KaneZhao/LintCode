#ifndef C77_H
#define C77_H
#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
* �����������
*
* ���������ַ������ҵ������������(LCS)������LCS�ĳ��ȡ�
* ˵��
* ����������еĶ��壺
* �������������������һ�����У�ͨ��2�������ҵ�����������У�ע�⣺��ͬ���Ӵ���LCS����Ҫ���������Ӵ������������ǵ��͵ļ������ѧ���⣬���ļ�����Ƚϳ���Ļ�������������Ϣѧ��Ҳ����Ӧ�á�
* https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
* ����
* ����"ABCD" �� "EDCA"�����LCS�� "A" (�� D��C)������1
* ���� "ABCD" �� "EACB"�����LCS��"AC"���� 2
*/
class Solution {
public:
	int longestCommonSubsequence(string A, string B) {
		// write your code here
		if (A.empty() || B.empty())
			return 0;
		int len_a = A.size(), len_b = B.size();
		//maxLen[i][j]��ʾA��ǰi���ַ���B��ǰj���ַ���,����������еĳ���
		vector<vector<int>> maxLen(len_a + 1, vector<int>(len_b + 1));
		for (int i = 0; i <= len_a; ++i)
			maxLen[i][0] = 0;
		for (int j = 1; j <= len_b; ++j)
			maxLen[0][j] = 0;
		//��A[i-1]==B[j-1],���������еĳ��ȼ�һ
		//����,maxLen[i][j]��ΪmaxLen[i][j-1]��maxLen[i-1][j]�Ľϴ�ֵ
		for (int i = 1; i <= len_a; ++i)
		{
			for (int j = 1; j <= len_b; ++j)
			{
				if (A[i - 1] == B[j - 1])
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				else
					maxLen[i][j] = maxVal(maxLen[i][j - 1], maxLen[i - 1][j]);
			}
		}
		return maxLen[len_a][len_b];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a:b;
	}
};

#endif