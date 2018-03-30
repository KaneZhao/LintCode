#ifndef C90_H
#define C90_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* k���� II
* 
* Your title here...Given n unique integers, number k (1<=k<=n) and target.
* Find all possible k integers where their sum is target.
* ����
* ����[1,2,3,4]��k=2�� target=5������ [[1,4],[2,3]]
*/
class Solution {
public:
	/*
	* @param A: an integer array
	* @param k: a postive integer <= length(A)
	* @param targer: an integer
	* @return: A list of lists of integer
	*/
	vector<vector<int>> kSumII(vector<int> &A, int k, int targer) {
		// write your code here
		vector<vector<int>> res;
		if (A.empty())
			return res;
		vector<int> nums;
		if (k == 1)
		{
			if (find(A.begin(), A.end(), targer) != A.end())
			{
				nums.push_back(targer);
				res.push_back(nums);
			}
			return res;
		}
		while (!A.empty())
		{
			int val = A[0];
			A.erase(A.begin());
			vector<int> tmp = A;
			//vec��ʾ���޳�val��������,�ҵ�k-1������Ϊtarger-val�Ľ��
			vector<vector<int>> vec = kSumII(tmp, k - 1, targer - val);
			//vec��Ϊ��,��val������
			if (!vec.empty())
			{
				for (auto &c : vec)
				{
					c.insert(c.begin(),val);
					res.push_back(c);
				}
			}
		}
		return res;
	}
};
#endif