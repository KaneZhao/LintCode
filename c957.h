#ifndef C957_H
#define C957_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* �״���
*
* һ��2Dƽ������һ���״�״���x, y���꣬�Լ���̽�⵽�ķ�Χr�뾶����������һ��С��Ҫ��y = 0��y = 1����������ͨ�����Ҳ��ܱ��״�̽�⵽��������⵽�����YES���������NO����������Ϊ��С����һ������Ϊ1���߶Σ���ֱ�ߴ�x = 0 ����ǰ����
* ע������
* �״�����Ϊn��n <= 1000��
* �״������xΪ�Ǹ�������yΪ������rΪ��������
* ����
* ���� coordinates = [[0,2]], radius = [1], ���� "NO"��
* ���ͣ�
* ��(0,2)���и��״����̽�⵽��(0,2)ΪԲ�ģ��뾶Ϊ1��Բ������С�����ᱻ��⵽��
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
	* @param coordinates: The radars' coordinate
	* @param radius: Detection radius of radars
	* @return: The car was detected or not
	*/
	string radarDetection(vector<Point> &coordinates, vector<int> &radius) {
		// Write your code here
		if (coordinates.empty() || radius.empty())
			return "NO";
		int len = coordinates.size();
		for (int i = 0; i < len; ++i)
		{
			if (isDetected(coordinates[i].y, radius[i]))
			{
				return "YES";
			}
		}
		return "NO";
	}
	//�ж��Ƿ���⵽,ֻ��y�����ֵ�й�
	bool isDetected(int y, int radius)
	{
		if (y >= 0 && y <= 1)
			return true;
		else if (y > 1)
		{
			if (y - radius < 1)
				return true;
			else
				return false;
		}
		else
		{
			if (y + radius>0)
				return true;
			else
				return false;
		}
	}
};
#endif