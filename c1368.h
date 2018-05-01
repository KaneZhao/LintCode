#ifndef C1368_H
#define C1368_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
/*
* ��ͬ����
*
* ��һ�����飬��������д�����ͬ���֣�����ͬ���ֵľ���С�ڸ���ֵk�����YES���������NO��
* ע������
* ��������鳤��Ϊn����֤n <= 100000��
* ����Ԫ�ص�ֵΪx��0 <= x <= 1e9��
* �����k���� 1 <= k < n��
* ����
* ���� array = [1,2,3,1,5,9,3], k = 4, ���� "YES"��
* ���ͣ�
* indexΪ3��1��indexΪ0��1����Ϊ3�������������YES��
* ���� array =[1,2,3,5,7,1,5,1,3], k = 4, ���� "YES"��
* ���ͣ�
* indexΪ7��1��indexΪ5��1����Ϊ2���������⡣
*/
class Solution {
public:
	/**
	* @param nums: the arrays
	* @param k: the distance of the same number
	* @return: the ans of this question
	*/
	string sameNumber(vector<int> &nums, int k) {
		// Write your code here
		if (nums.empty())
			return "NO";
		map<int, int> m;//������ּ���λ��
		for (int i = 0; i < nums.size(); ++i)
		{
			//���֮ǰ���ֹ�nums[i],����λ�ú�֮ǰ��λ�þ���С�ڸ���ֵk,����YES
			//����,��m[nums[i]]����Ϊ��ǰλ��
			if (m.find(nums[i]) != m.end())
			{
				if (i - m[nums[i]] < k)
					return "YES";
				else
					m[nums[i]] = i;
			}
			else
				m[nums[i]] = i;
		}
		return "NO";
	}
};
#endif