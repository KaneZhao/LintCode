#ifndef C666_H
#define C666_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ������Ϸ II
*
* ���������������Ϸ, ��Ϸ��������:
* ���� 1�� n �ķ�Χ��ѡ��һ������Ϊ���µ���, ����Ҫ���������,
* ÿ����´��ʱ��, �һ��������ѡ���������Ǳ���˵����Ҫ�߻��ǵ�,
* ����, ����������Ϊ x ���Ҳ´��ʱ������Ҫ֧�� $x. ����µ���ѡ�����ʱ, �㽫Ӯ���ⳡ��Ϸ
* ����
* ���� n = 10, ��ѡ�������Ϊ 8
* ��һ��: ��²�Ϊ 5, �Ҹ�������µ�ֵҪ����һЩ. ����Ҫ֧�� $5
* �ڶ���: ��²�Ϊ 7, �Ҹ�������µ�ֵҪ����һЩ. ����Ҫ֧�� $7
* ������: ��²�Ϊ 9, �Ҹ�������µ�ֵҪ��СһЩ. ����Ҫ֧�� $9
* ��Ϸ����. 8 ����ѡ��Ĵ�����.
* ��������Ҫ֧�� $5 + $7 + $9 = $21
* ��һ������Ĵ��ڵ��� 1 ���� n, ��������Ҫ����Ǯ�ſ��Ա�֤Ӯ.
* ���Ե� n = 10 ʱ, ���� 16.
*/
class Solution {
public:
	/*
	* @param n: An integer
	* @return: how much money you need to have to guarantee a win
	*/
	int getMoneyAmount(int n) {
		// write your code here
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));//dp[i][j]��ʾ��i-jӮ,����Ҫ����СǮ��
		//�׵����鳤��Ϊ1,��ҪǮ��Ϊ0,��dp[i][i]��������ĳ�ʼ��
		//�ӳ���Ϊ2�������鿪ʼ����,��1-2,2-3,3-4
		//����������i - i+path,�����һ��ȡÿ��λ��ʱ����СǮ��,��ȡ����Ǯ������Сֵ
		for (int path = 1; path < n; ++path)
		{
			for (int i = 1; i + path <= n; ++i)
			{
				int res = INT_MAX;
				int tmp = INT_MAX;
				for (int j = i; j <= i + path; ++j)
				{
					if (j == i)
						tmp = j + dp[j + 1][i + path];
					else if (j == i + path)
						tmp = dp[i][j - 1] + j;
					else
						tmp = j + maxVal(dp[i][j - 1],dp[j + 1][i + path]);//jλ���������м�λ��,ȡ����������Ǯ�������ֵ
					res = minVal(res, tmp);
				}
				dp[i][i + path] = res;
			}
		}
		return dp[1][n];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif