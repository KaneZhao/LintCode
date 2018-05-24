#ifndef C832_H
#define C832_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ͳ�Ƹ���
*
* ��һ�����������������Ҳ����ĵ� n * m�ľ��� �������м�������
* ע������
* ����ľ����СΪ n x m ��n <= 500��m <= 500��
* Ϊ��Լ�������ʱ�临�Ӷȣ���ĳ��򽫻����� 10^5 ��
* ����
* Given mat =
* [
* [-5,-3,-1,0,1],
* [-2,-1,0,0,1],
* [0,11,12,12,14]
* ],
* return 5.
* Explanation:
* There are only 5 negative number.
*/
class Solution {
public:
	/**
	* @param nums: the sorted matrix
	* @return: the number of Negative Number
	*/
	int countNumber(vector<vector<int>> &nums) {
		// Write your code here
		if (nums.empty() || nums[0].empty())
			return 0;
		int row = nums.size(), col = nums[0].size();
		int i = 0, j = col - 1;
		int cnt = 0;
		//�ж��������Ͻ����Ƿ�Ϊ����
		//�����Ǹ���,����û�и���,ȥǰһ��Ѱ��
		//���Ǹ���,�ڱ��д���֮ǰ�������Ǹ���,֮��ȥ��һ��Ѱ��
		while (i < row&&j >= 0)
		{
			if (nums[i][j] >= 0)
				j--;
			else
			{
				cnt += (j + 1);
				i++;
			}
		}
		return cnt;
	}
};
#endif 