#ifndef C692_H
#define C692_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* ����������ΨһԪ��������
*
* ��һ�������һ���������ڵĴ�С, ��ÿһ��������ΨһԪ�صĸ�����
* ����
* ��һ������ nums = [1, 2, 1, 3, 3] �� k = 3
* ��һ������Ϊ [1, 2, 1], ֻ�� 2 ��Ψһ��, ����Ϊ 1.
* �ڶ�������Ϊ [2, 1, 3], ���е�Ԫ�ض���Ψһ��, ����Ϊ 3.
* ����������Ϊ [1, 3, 3], ֻ�� 1 ��Ψһ��, ����Ϊ 1.
* ����Ϊ 1 + 3 + 1 = 5
* ���� 5
*/
class Solution {
public:
	/*
	* @param : the given array
	* @param : the window size
	* @return: the sum of the count of unique elements in each window
	*/
	int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
		// write your code here
		if (nums.empty() || k <= 0)
			return 0;
		int len = nums.size();
		map<int, int> m;
		int res = 0;
		if (k == 1)//���ڴ�СΪ1,ÿ�������ڵĸ���Ϊ1
			return len;
		else if (k >= len)//��k>=len,���൱����nums��ΨһԪ�صĸ���
		{
			for (auto c : nums)
				m[c]++;
			for (auto t : m)
			{
				if (t.second == 1)
					res++;
			}
			return res;
		}
		else
		{
			int cnt = 0;
			//i=0,����map��ʾ������ÿ������Ԫ�صĸ���
			for (int l = 0; l < k; ++l)
				m[nums[l]]++;
			for (auto t : m)
			{
				if (t.second == 1)
					cnt++;
			}
			res += cnt;
			//����i,����m�Լ�cnt
			//��m[nums[i-1]]�Լ�,��ֵΪ1,��֮ǰnums[i-1]���ִ���Ϊ2,cnt++
			//��ֵΪ0,��֮ǰnums[i-1]���ִ���Ϊ1,���ڴ���û��nums[i-1],cnt--
			//���������Ӱ��cnt��ֵ
			for (int i = 1; i + k <= len; ++i)
			{
				m[nums[i - 1]]--;
				if (m[nums[i - 1]] == 1)
					cnt++;
				else if (m[nums[i-1]]==0)
					cnt--;
				m[nums[i + k - 1]]++;
				if (m[nums[i + k - 1]] == 1)
					cnt++;
				else if (m[nums[i+k-1]]==2)
					cnt--;
				res += cnt;
			}
			return res;
		}
	}
};
#endif