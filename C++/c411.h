#ifndef C411_H
#define C411_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
* ���ױ���
* 
* ���ױ�����һ������������ϵͳ���ڸ�ϵͳ�У�������������ֵ����һ�������ƵĲ��졣
* ����һ���Ǹ����� n ����ʾ�ô��������ж����Ƶ����������ҳ�����ױ���˳��һ�����ױ���˳������� 0 ��ʼ�����������е� 2n ��������
* ע������
* ���ڸ����� n������ױ���˳�򲢲�Ψһ��
* �������϶��壬 [0,2,3,1] Ҳ��һ����Ч�ĸ��ױ���˳��
* ����
* ���� n = 2�� ���� [0,1,3,2]������ױ���˳��Ϊ��
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* ��ս
* O(2n) ʱ�临�Ӷȡ�
*/
class Solution {
public:
	/*
	* @param n: a number
	* @return: Gray code
	*/
	vector<int> grayCode(int n) {
		// write your code here
		vector<int> res(pow(2,n),0);
		//��n=0�����Ϊ{0}����n=1�����Ϊ{0,1}; 
		//�ɹ��ɿɵã�n = 2ʱ��ǰ�������{ 00��01 }����������{ 0��1 }ÿ������ǰ���1�ĵ���
		//��Ϊ{ 11, 10 }���ݹ��������
		if (n <= 0)
			return res;
		if (n == 1)
		{
			res[1] = 1;
			return res;
		}
		vector<int> v = grayCode(n - 1);
		for (int i = 0; i < v.size(); ++i)
		{
			res[i] = v[i];
			res[res.size() - 1 - i] = v[i] + pow(2, n - 1);
		}
		return res;
	}
};
#endif