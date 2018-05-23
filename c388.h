#ifndef C388_H
#define C388_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* ��k������
*
* ����
* ���� n �� k����123..n��ɵ������еĵ� k �����С�
* 1 �� n �� 9
* ����
* ���� n = 3, ���е��������£�
* 123
* 132
* 213
* 231
* 312
* 321
* ��� k = 4, ��4������Ϊ��231.
* ��ս
* O(n*k) in time complexity is easy, can you do it in O(n^2) or less?
*/
class Solution {
public:
	/*
	* @param n: n
	* @param k: the k th permutation
	* @return: return the k-th permutation
	*/
	string getPermutation(int n, int k) {
		// write your code here
		string res;
		if (n <= 0 || k <= 0)
			return res;
		vector<char> nums;//��ų�ʼ����
		int m = 1;
		//m��ʾ��nums����һԪ�ؿ�ͷ��������
		for (int i = 1; i < n; ++i)
			m *= i;
		for (int i = 0; i <= n; ++i)
			nums.push_back(i + '0');
		//numΪԪ����nums�е�λ��,���num��Ӧ���ַ�
		//����k��m��ֵ
		for (int i = 1; i < n; ++i)
		{
			int num = (k - 1) / m + 1;
			if (k == 0)
				num = nums.size() - 1;
			res += nums[num];
			k %= m;
			m /= n - i;
			nums.erase(nums.begin() + num);
		}
		res += nums[1];
		return res;
	}
};
#endif