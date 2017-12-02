#ifndef C706_H
#define C706_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* ����һ����������ʾʱ����ֱ��һ���Ǹ����� n, n �����ڸ���ʱ����� 1 ������, �������п��ܵ�ʱ��
*
* ע������
* �����˳��û��Ҫ��.
* Сʱ���ܰ���ǰ����, ���� "01:00" �ǲ������, Ӧ��Ϊ "1:00".
* ���ӱ�������λ�����, ���ܰ���ǰ����, ���� "10:2" ����Ч��, Ӧ��Ϊ "10:02".
*
* ����
* ���� n = 1
* ���� ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/
class Solution {
public:
	/*
	* @param : the number of "1"s on a given timetable
	* @return: all possible time
	*/
	vector<string> binaryTime(int num) {
		// Write your code here
		vector<string> res;
		//num��0-8֮��������
		if (num == 0)
			return{ "0:00" };
		if (num >= 9)
			return res;
		vector<vector<int>> dic(6, vector<int>());//�洢����0-5��1������
		for (int i = 0; i < 60; ++i)
			dic[countOne(i)].push_back(i);
		//��Сʱ���ֿ�ʼ����
		for (int i = 0; i <= 3; ++i)
		{
			//��Ҫ���ϵ�һЩ����
			if (num - i <= 5 && num - i >= 0)
			{
				//������Ӳ���
				for (auto c : dic[i])
				{
					if (c < 12)
					{
						for (auto t : dic[num - i])
						{
							string str;
							if (t >= 10)
								 str = to_string(c) + ":" + to_string(t);
							else
								 str = to_string(c) + ":0" + to_string(t);
							res.push_back(str);
						}
					}
				}
			}
		}
		return res;
	}
	//���������а���1�ĸ���
	int countOne(int num)
	{
		int cnt = 0;
		while (num != 0)
		{
			if (num & 1 != 0)
				cnt++;
			num = num >> 1;
		}
		return cnt;
	}
};
#endif