#ifndef C662_H
#define C662_H
#include<iostream>
using namespace std;
/*
* ������Ϸ
*
* ���������������Ϸ�� ��Ϸ���£�
* �Ҵ� 1 �� n ѡ��һ�����֡� ����Ҫ����ѡ�����ĸ����롣
* ÿ����´��ˣ��һ��������������Ǹ߻��ǵ͡�
* �����һ��Ԥ����Ľӿ� guess(int num)�����᷵�� 3 �����ܵĽ��(-1��1��0):
* ����
* n = 10, ��ѡ���� 4 (�����㲻֪��)
* ���� 4����ȷ��
*/
class Solution {
public:
	/**
	* @param n an integer
	* @return the number you guess
	*/
	int guessNumber(int n) {
		// Write your code here
		int low = 1, high = n;
		while (low<=high)
		{
			int mid = low + (high - low) / 2;
			int m = guess(mid);
			if (m == 1)
				low = mid + 1;
			else if (m == 0)
				return mid;
			else
				high = mid - 1;
		}
	}
	/*
	int guess(int num)
	{
		if (num > goal)
			return -1;
		else if (num == goal)
			return 0;
		else
			return 1;
	}
	int goal;
	*/
};
#endif