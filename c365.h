#ifndef C365_H
#define C365_H
#include<iostream>
#include<Windows.h> 
using namespace std;
/*
* ���������ж��ٸ�1
*
* ������һ�� 32 λ�������Ķ����Ʊ�ʾ���ж��ٸ� 1.
* ����
* ���� 32 (100000)������ 1
* ���� 5 (101)������ 2
* ���� 1023 (1111111111)������ 10
* ��ս
* If the integer is n bits with m 1 bits. Can you do it in O(m) time?
*/
class Solution {
public:
	/*
	* @param num: An integer
	* @return: An integer
	*/
	int countOnes(int num) {
		// write your code here
		if (num < 0)
			return 32 - countOnesRecur(num);
		else
			return countOnesRecur(num);
	}
	int countOnesRecur(int num)
	{
		int count = 0;
		if (num < 0)
		{
			num = -1 ^ num;
		}
		if (num == 1)
			return 1;
		if (num == 0)
			return 0;
		if (num % 2 == 0)
			return countOnes(num >> 1);
		else
			return countOnes(num >> 1) + 1;
	}
};
class Solution2 {
public:
	/*
	* @param num: An integer
	* @return: An integer
	*/
	int countOnes(int num) {
		// write your code here
		//��һ��������ȥ1���ٺ�ԭ���������㣬��Ѹ��������ұߵ�1��Ϊ0��һ�������Ķ����Ʊ�ʾ���ɶ��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����
		int cnt = 0;
		while (num)
		{
			++cnt;
			num = (num - 1)&num;
		}
		return cnt;
	}
};
#endif