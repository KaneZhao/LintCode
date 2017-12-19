#ifndef C700_H
#define C700_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ���ӷָ�
* ��һ�� n Ӣ�糤�ĸ��Ӻ�һ����������С�� n �ĳߴ�ļ۸�. ȷ��ͨ���и�˲�������Ƭ�ɻ�õ����ֵ.���磬������ĳ���Ϊ8�����Ҳ�ͬ���Ȳ�����ֵ���£������ɻ��ֵΪ 22(ͨ���и����γ��� 2 �� 6 )
*
* ����
* ����    | 1   2   3   4   5   6   7   8
* --------------------------------------------
* �۸�    | 1   5   8   9  10  17  17  20
* ���� price = [1, 5, 8, 9, 10, 17, 17, 20], n = 8 ���� 22//�гɳ���Ϊ 2 �� 6 ������
*
* ����    | 1   2   3   4   5   6   7   8
* --------------------------------------------
* �۸�    | 3   5   8   9  10  17  17  20
* ���� price = [3, 5, 8, 9, 10, 17, 17, 20], n = 8 ���� 24//�гɳ���Ϊ 1 �� 8 ��
*/
class Solution {
public:
	/*
	* @param : the prices
	* @param : the length of rod
	* @return: the max value
	*/
	int cutting(vector<int>& prices, int n) {
		// Write your code here
		if (n == 0 || prices.empty())
			return 0;
		vector<int> dp(n + 1, 0);
		//��̬ת������dp[i] = max{ dp[j] + dp[i - j] }
		for (int i = 1; i <= n; ++i)
		{
			dp[i] = prices[i - 1];
			for (int j = 0; j <= i / 2; ++j)
			{
				dp[i] = maxVal(dp[i], dp[j] + dp[i - j]);
			}
		}
		return dp[n];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif