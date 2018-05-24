#ifndef C76_H
#define C76_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �����������
* 
* ����һ���������У��ҵ�����������У�LIS��������LIS�ĳ��ȡ�
* ˵��
* ����������еĶ��壺
* �������������������һ������ĸ����������ҵ�һ�������ܳ����ɵ͵������е������У����������в�һ���������Ļ���Ψһ�ġ�
* https://en.wikipedia.org/wiki/Longest_increasing_subsequence
* ����
* ���� [5,4,1,2,3]��LIS �� [1,2,3]������ 3
* ���� [4,2,4,5,3,7]��LIS �� [2,4,5,7]������ 4
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(n^2) ���� O(nlogn)
*/
class Solution{
public:	
	int longestIncreasingSubsequence(vector<int> nums) {
		// write your code here
		if (nums.empty())
			return 0;
		int len = nums.size();
		vector<int> res(len, 0);//res[i]�����nums[i]Ϊβ����������еĳ���
		res[0] = 1;
		for (int i = 1; i < len; ++i)
		{
			int tmp = 1;
			for (int j = i - 1; j >= 0; --j) //�Ӻ���ǰѰ�ұ�nums[i]С��Ԫ��,�䳤�ȵ����ֵ
			{
				if (nums[i]>nums[j])
				{
					tmp = maxVal(tmp, res[j] + 1);
				}
			}
			res[i] = tmp;
		}
		int max = 1;
		for (auto c : res) //�ҳ���󳤶�
		{
			if (c > max)
				max = c;
		}
		return max;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};

#endif