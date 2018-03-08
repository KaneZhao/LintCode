#ifndef C830_H
#define C830_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
* �ַ�������
*
* ����һ���ַ���������õ��ַ�Ϊ��һ�ؼ��֣��ֵ�˳��Ϊ�ڶ��ؼ��������ַ�����
* ע������
* �ַ������ȴ�СС��10000
* �����ַ���ΪСд
* ����
* ���� str = ��bloomberg�� , ���� ��bbooeglmr����
* ���ͣ�
* 'b'���ִ�����࣬���ֵ�����С��������һ�������'o'��
* ���� str = ��lintcode��, ���� ��cdeilnot����
* ���ͣ�
* �����ַ����ִ���һ���࣬����ֱ�Ӱ����ֵ�������
*/
typedef pair<int, long long> node;
bool cmp(const node &a, const node &b)
{
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;
}
class Solution {
public:
	/**
	* @param str: the string that needs to be sorted
	* @return: sorted string
	*/
	string stringSort(string &str) {
		// Write your code here
		if (str.empty())
			return str;
		map<int, long long> map;
		vector<node> vec;
		for (auto c : str)
		{
			map[c - 'a']++;
		}
		for (auto t : map)
		{
			vec.push_back(make_pair(t.first, t.second));
		}
		sort(vec.begin(), vec.end(), cmp);
		str.clear();
		for (auto t : vec)
		{
			for (long long i = 0; i < t.second; ++i)
			{
				str += 'a' + t.first;
			}
		}
		return str;
	}
};
#endif