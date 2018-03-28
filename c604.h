#ifndef C604_H
#define C604_H
#include<iostream>
#include<vector>
using namespace std;
/*
* �������������ĺ�
*
* ����һ����СΪn�����������һ����СΪk�Ļ������ڣ����������ڴ�ͷ�Ƶ�β������ӿ�ʼ������ÿһ��ʱ�̻��������ڵ����ĺ͡�
* ����
* �������� [1,2,7,8,5] ���������ڴ�Сk= 3 ��
* 1 + 2 + 7 = 10
* 2 + 7 + 8 = 17
* 7 + 8 + 5 = 20
* ���� [10,17,20]
*/
class Solution {
public:
	/**
	* @param nums: a list of integers.
	* @param k: length of window.
	* @return: the sum of the element inside the window at each moving.
	*/
	vector<int> winSum(vector<int> &nums, int k) {
		// write your code here
		vector<int> res;
		//��numsΪ�ջ�k<=0,���ؿ�
		if (nums.empty() || k <= 0)
			return res;
		int sum = 0;
		for (int i = 0; i < k; ++i)
			sum += nums[i];
		res.push_back(sum);
		//���ڻ�������,sum��ȥnums[j-1]����nums[j+k-1]�������ڴ����ڵ�Ԫ��֮��
		for (int j = 1; j + k - 1 < nums.size(); ++j)
		{
			sum -= nums[j - 1];
			sum += nums[j + k - 1];
			res.push_back(sum);
		}
		return res;
	}
};
#endif