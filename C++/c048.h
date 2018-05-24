#ifndef C48_H
#define C48_H
#include<vector>
#include<iostream>
#include<map>
using namespace std;
/*
* ��Ԫ�� III
*
* ����һ���������飬�ҵ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ�����1/k��
* ע������
* ������ֻ��Ψһ����Ԫ��
* ����
* �������� [3,1,2,3,2,3,3,4,4,4] ���� k = 3������ 3
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(k)
*/
class Solution {
public:
	int majorityNumber(vector<int> nums, int k) {
		map<int, int> m;
		int size = nums.size();
		//�ҵ�k����ͬ�����͵���
		for (int i = 0; i < size; ++i)
		{
			if (m.size() < k)
			{
				m[nums[i]]++;			
			}
			else
			{
				if (m.find(nums[i]) != m.end())
					m[nums[i]]++;
				else
				{
					for (auto &c : m)
					{
						c.second--;
					}
					for (auto it = m.begin(); it != m.end();)
					{
						if (it->second <= 0)
						{
							m.erase(it++);
						}
						else
						{
							it++;
						}
					}
				}
			}
		}
		for (auto &c : m)
		{
			c.second = 0;
		}
		for (auto t : nums)
		{
			if (m.find(t) != m.end())
				m[t]++;
		}
		int res = 0;
		int cnt = INT_MIN;
		for (auto c : m)
		{
			if (cnt < c.second)
			{
				cnt = c.second;
				res = c.first;
			}
		}
		return res;
	}
};
#endif