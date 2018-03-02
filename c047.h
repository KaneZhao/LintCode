#ifndef C47_H
#define C47_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��Ԫ�� II
*
* ����һ���������飬�ҵ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ���������֮һ��
* ע������
* ������ֻ��Ψһ����Ԫ��
* ����
* ��������[1,2,1,2,1,3,3] ���� 1
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
class Solution {
public:
	int majorityNumber(vector<int> nums) {
		if (nums.empty())
			return -1;
		int size = nums.size();
		if (size <= 2)
			return nums[0];
		int temp1 = INT_MIN, temp2 = INT_MIN;
		int cnt1 = 0, cnt2 = 0;
		//����ҵ�������һ������,�͵���
		for (int i = 0; i < size; ++i)
		{
			if (cnt1 == 0&&nums[i]!=temp2)
			{
				temp1 = nums[i];
				cnt1++;
				continue;
			}
			if (cnt2 == 0&&nums[i]!=temp1)
			{
				temp2 = nums[i];
				cnt2++;
				continue;
			}
			if (nums[i] != temp1&&nums[i] != temp2)
			{
				cnt1--;
				cnt2--;
			}
			else
			{
				if (nums[i] == temp1)
					cnt1++;
				else
					cnt2++; 
			}
		}
		//��temp1��temp2��ѡ����ִ����϶���Ǹ�
		cnt1 = 0, cnt2 = 0;
		for (auto c : nums)
		{
			if (c == temp1)
				cnt1++;
			else if (c == temp2)
				cnt2++;
		}
		return cnt1 > cnt2 ? temp1 : temp2;
	}
};
#endif