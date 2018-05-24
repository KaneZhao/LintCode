#ifndef C805_H
#define C805_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
/*
* ����������
*
* �������飬ÿ���鶼����������Ժ�ǿ���飬����ListA��ListB����ʾListA[i]��ListB[i]�й�������������������󼯺ϡ�(�������˳��)����Ŀ��ֻ֤��һ�����ļ��ϡ�
* ע������
* �鼮���������ᳬ��5000��
* ����
* ����ListA = ["abc","abc","abc"], ListB = ["bcd","acd","def"], ���� ["abc","acd","bcd","dfe"]��
* ���ͣ�
* abc��bcd,acd,dfe���й������������ļ��Ͼ���ȫ���鼮���ɵļ��ϡ�
* ���� ListA = ["a","b","d","e","f"], ListB = ["b","c","e","g","g"], ����["d","e","g","f"]��
* ���ͣ�
* ��ǰ�ļ�����[a,b,c],[d,e,g,f],��ô���ļ�����[d,e,g,f]��
*/
class Solution {
public:
	/**
	* @param ListA: The relation between ListB's books
	* @param ListB: The relation between ListA's books
	* @return: The answer
	*/
	vector<string> maximumAssociationSet(vector<string> &ListA, vector<string> &ListB) {
		// Write your code here
		vector<string> res;
		if (ListA.empty() || ListB.empty())
			return res;
		map<string, string> m;
		map<string, int> count;
		//m���ListA,ListB�г��ֵ����е��ַ���,����ʼ��
		for (auto c : ListA)
		{
			if (m.find(c) == m.end())
				m[c] = c;
		}
		for (auto t : ListB)
		{
			if (m.find(t) == m.end())
				m[t] = t;
		}
		//����ÿ���й����Ե��鼮,������߲���鼮,�����кϲ�
		for (int i = 0; i < ListA.size(); ++i)
		{
			string root1 = unionSearch(ListA[i], m);
			string root2 = unionSearch(ListB[i], m);
			if (root1 != root2)
				m[root1] = root2; 
		}
		//��m����·��ѹ��
		for (auto &c : m)
		{
			c.second = unionSearch(c.first, m);
		}
		//�����߲��鼮,����Щ�鼮����鼮�ı���
		for (auto c : m)
		{
			count[c.second]++;
		}
		//������߲��鼮��ص���������߲��鼮������
		int max = INT_MIN;
		string str;
		for (auto p : count)
		{
			if (p.second >= max)
			{
				str = p.first;
				max = p.second;
			}
		}
		//���������ҵ�����鼮
		for (auto t : m)
		{
			if (t.second == str)
				res.push_back(t.first);
		}
		return res;
	}
	//�ҵ�root����߲���
	string unionSearch(string root, map<string, string> &m)
	{
		while (root != m[root])
		{
			m[root] = m[m[root]];
			root = m[root];
		}
		return root;
	}
};
#endif