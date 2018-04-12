#ifndef C896_H
#define C896_H
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*
* �����˻�
*
* ����һ�����ظ�����������arr��ÿ���������ʹ��һ�Σ����������ظ��ĳ˻�����С��������
* ע������
* 2 <= |arr| <= 9
* 2 <= arr[i] <= 23
* ����
* ���� arr = [2,3], ���� [6]��
* ���ͣ�
* 2*3=6��
* ���� arr = [2,3,5], ���� [6,10,15,30]��
* ���ͣ�
* 2*3=6, 2*5=10, 3*5=15, 2*3*5=30��
*/
class Solution {
public:
	/**
	* @param arr: The prime array
	* @return: Return the array of all of prime product
	*/
	vector<int> getPrimeProduct(vector<int> &arr) {
		// Write your code here
		vector<int> res;
		sort(arr.begin(), arr.end());
		//��arr��ǰ����Ԫ�س�ʼ��res
		res.push_back(arr[0] * arr[1]);
		//ÿ����һ��Ԫ��arr[i],��res�����arr��iλ��֮ǰ��Ԫ����arr[i]�ĳ˻�
		//�����ԭres������Ԫ����arr[i]�ĳ˻�
		for (int i = 2; i < arr.size(); ++i)
		{
			int len = res.size();
			for (int j = 0; j < i; ++j)
				res.push_back(arr[i] * arr[j]);
			for (int k = 0; k < len; ++k)
				res.push_back(arr[i] * res[k]);
		}
		sort(res.begin(), res.end());
		return res;
	}
};
#endif