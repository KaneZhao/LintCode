#ifndef C42_H
#define C42_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��������� II
*
* ����һ���������飬�ҳ����� ���ص� ������ʹ�����ǵĺ����
* ÿ��������������������е�λ��Ӧ���������ġ�
* �������ĺ͡�
* ע������
* ���������ٰ���һ����
* ����
* �������� [1, 3, -1, 2, -1, 2]
* ������������ֱ�Ϊ [1, 3] �� [2, -1, 2] ���� [1, 3, -1, 2] �� [2]�����ǵ����Ͷ��� 7
* ��ս
* Ҫ��ʱ�临�Ӷ�Ϊ O(n)
*/
class Solution {
public:
	int maxTwoSubArrays(vector<int> nums) {
		int res1 =INT_MIN, res2 = INT_MIN;
		int Max = INT_MIN;
		int tmp1 = 0, tmp2 = 0;
		int len = nums.size();
		vector<int> left(len, 0);
		vector<int> right(len, 0);
		//left[i]��ʾnums[0]��nums[i]��ʾ������,��������͵����ֵ
		for (int i = 0; i<len; ++i)
		{
			if (tmp1<0)
				tmp1 = 0;
			tmp1 += nums[i];
			res1 = maxVal(res1, tmp1);
			left[i] = res1;
		}
		//right[j]��ʾnums[j]��nums[len-1]��ʾ������,��������͵����ֵ
		for (int j = len - 1; j >= 0; --j)
		{
			if (tmp2<0)
				tmp2 = 0;
			tmp2 += nums[j];
			res2 = maxVal(res2, tmp2);
			right[j] = res2;
		}
		//������������͵����ֵ
		for (int k = 0; k<len - 1; ++k)
		{
			Max = maxVal(Max, left[k] + right[k + 1]);
		}
		return Max;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif