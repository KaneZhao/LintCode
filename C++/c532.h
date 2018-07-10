#ifndef C532_H
#define C532_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* �����
*
* ����
* �������е������������ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬����������������Ե�������
* ���������a[i] > a[j] �� i < j�� a[i] �� a[j] ����һ������ԡ�
* ����
* ���� [2, 4, 1, 3, 5] �У��� 3 ������� (2, 1), (4, 1), (4, 3)���򷵻� 3 ��
*/
class Solution {
public:
	/*
	* @param A: an array
	* @return: total of reverse pairs
	*/
	long long reversePairs(vector<int> &A) {
		// write your code here
		if (A.empty())
			return 0;
		int len = A.size(); 
		long long cnt = 0;
		vector<int> vec;
		vec.push_back(A.back());
		for (int i = len - 2; i >= 0; --i)
		{
			int pos = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin();
			vec.insert(vec.begin() + pos, A[i]);
			cnt += pos;
		}
		return cnt;
	}
};
#endif