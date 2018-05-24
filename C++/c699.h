#ifndef C699_H
#define C699_H
#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
/*
* ���������� n �� k. ������Ҫ�ж� n �Ƿ����д�� k �������ĺ�.
* ע������
* n <= 10 ^ 9
* 
* ��°ͺյĲ���
* ��һ����2��ż������д����������֮��
*/
class Solution {
public:
	/*
	* @param : an int
	* @param : an int
	* @return: if N can be expressed in the form of sum of K primes, return true; otherwise, return false.
	*/
	bool isSumOfKPrimes(int n, int k) {
		// write your code here
		//������С������Ϊ2����n<2kʱ��������ʵ�֣�����false
		if (n<2*k||k <= 0)
			return false;
		if (k == 1)
			return isPrime(n);
		//��kҲΪż����k=2q����n>=4q��n���Էֳ�q�����ڵ���4���������ݲ��룬ÿ�����ֿ��Ա�ʾΪ���������ĺͣ��ʿ��Ա�ʾΪk����2q���������ĺͣ�����true
		//��kΪ������Ϊ�˱�֤n������k�����ĺͣ��ش�������2������isSumOfKPrimes(n - 2, k - 1)
		if (n % 2 == 0)
		{
			if (k%2==0)
				return true;
			else
				return isSumOfKPrimes(n - 2, k - 1);
		}
		//��kΪż����n��������ż����������ɣ��ش�������2������isSumOfKPrimes(n - 2, k - 1)
		//��kΪ��������Ȼ��������һ������������isSumOfKPrimes(n - 3, k - 1)
		else
		{
			if (k %2==0)
				return isSumOfKPrimes(n - 2, k - 1);
			else
				return isSumOfKPrimes(n - 3, k - 1);
		}
	}
	//�ж��Ƿ�������
	bool isPrime(int num)
	{
		if (num < 2)
			return false;
		for (int i = 2; i*i < num; ++i)
		{
			if (num%i == 0)
				return false;
		}
		return true;
	}
};
#endif