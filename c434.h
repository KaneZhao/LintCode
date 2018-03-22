#ifndef C434_H
#define C434_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ����ĸ���II
*
* ���� n��m���ֱ����һ��2D�����������������ͬʱ������һ����СΪ k �Ķ�Ԫ����A�������2D�����������������Ϊ 0�����þ�����ֻ�к��󡣶�Ԫ������ k ���������ÿ��������� 2 ������ A[i].x, A[i].y�����ͨ���ı���������е�A[i].x]��[A[i].y] �������ɺ����Ϊ���졣����ÿ������󣬷��ؾ����е����������
* ע������
* 0 ������1 �������������1���ڣ���ô������1����ͬһ����������ֻ������������Ϊ���ڡ�
* ����
* ���� n = 3, m = 3�� ��Ԫ���� A = [(0,0),(0,1),(2,2),(2,1)].
* ���� [1,1,2,2].
*/
struct Point{
	int x;
	int y;
	Point() :x(0), y(0){}
	Point(int a, int b) :x(a), y(b){}
};
class Solution {
public:
	/**
	* @param n: An integer
	* @param m: An integer
	* @param operators: an array of point
	* @return: an integer array
	*/
	vector<int> numIslands2(int n, int m, vector<Point> &operators) {
		// write your code here
		vector<int> res;
		if (n <= 0 || m <= 0 || operators.empty())
			return res;
		vector<int> nums(n*m + 1, 0);
		vector<vector<int>> dic{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		int count = 0;
		for (auto c : operators)
		{
			int pos = c.x*m + c.y + 1;
			//��pos�Ѿ����ֹ�,�򷵻ص�ǰ��countֵ
			if (nums[pos] != 0)
			{
				res.push_back(count);
				continue;
			}
			nums[pos] = pos;
			++count;
			//�����뵱ǰλ�����ڵ�λ��
			//�ҵ�����λ��cur����ֵ,����ֵ��nums[pos]
			//��ʱ�����ں�,count��һ
			for (auto t : dic)
			{
				int a = c.x + t[0];
				int b = c.y + t[1];
				int cur = a*m + b + 1;
				if (a < 0 || a >= n || b < 0 || b >= m || nums[cur] == 0)
					continue;
				int root = unionSearch(cur, nums);
				if (pos != root)
				{
					nums[pos] = root;
					pos = root;
					--count;
				}
			}
			res.push_back(count);
		}
		return res;
	}
	//����root����ֵ,������·��ѹ��
	int unionSearch(int root, vector<int>&nums)
	{
		while (root != nums[root])
		{
			nums[root] = nums[nums[root]];
			root = nums[root];
		}
		return root;
	}
};
#endif