#ifndef C46_H
#define C46_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ��Ԫ��
*
* ����һ���������飬�ҳ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ����Ķ���֮һ��
* ע������
* You may assume that the array is non-empty and the majority number always exist in the array.
* ����
* ��������[1,1,1,1,2,2,2]������ 1
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
*/
class Solution {
public:
	int majorityNumber(vector<int> &nums) {
		// write your code here
		int size = nums.size();
		int temp = nums[0];
		int cnt = 1;
		for (int i = 1; i < size; ++i)
		{
			//��cntΪ0,��temp��Ϊ��ǰԪ��
			if (cnt == 0)
				temp = nums[i];
			//����ǰԪ�ص���temp,cnt++;����,����,cnt--
			if (nums[i] == temp)
				cnt++;
			else
				cnt--;
		}
		return temp;
	}
};
#endif