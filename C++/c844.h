#ifndef C844_H
#define C844_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ����ͳ��
*
* ��һ��<Point>��List p��������p[i].x+p[j].x��p[i].y+p[j].y��i < j)���ܱ�2������(i,j)������
* ע������
* �����list����len <= 10000��
* ����
* ���� p = [[1,2],[3,4],[5,6]], ���� 3��
* ���ͣ�
* p[0],p[1],p[2]������ϣ�����x��y֮�Ͷ��ܱ�2������
* ���� p = [[0,3],[1,1],[3,4],[5,6]], ���� 1��
* ���ͣ�
* ֻ��p[2]��p[3]��ϣ����ǵ�x��y֮�Ͷ��ܱ�2������
*/
class Point{
public:
	int x, y;
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};
class Solution {
public:
	/**
	* @param p: the point List
	* @return: the numbers of pairs which meet the requirements
	*/
	int pairNumbers(vector<Point> &p) {
		// Write your code here
		if (p.empty())
			return 0;
		int cnt = 0;
		int len = p.size();
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if ((p[i].x + p[j].x) % 2 == 0 && (p[i].y + p[j].y) % 2 == 0)
					cnt++;
			}
		}
		return cnt;
	}
};
#endif