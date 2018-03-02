#ifndef C819_H
#define C819_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ��������
* 
* ��һ���µ���ĸ����{c,b,a,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}�������µ���ĸ�������ַ������顣
* ע������
* ����ĵ��ʳ��Ȳ�����100��
* ����ĵ�������������10000��
* ������Ϊ�����������ĸ��һ������Ϊ26���ַ�����
* ��֤��Ŀֻ�����Сд��ĸ��
* ����
* ���� Alphabet = {c,b,a,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}, String array = {cab,cba,abc}, ���� {cba,cab,abc}��
* ���ͣ�
* �����µ��ֵ����������{cba,cab,abc}��
* ���� Alphabet = {z,b,a,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,c}, String array = {bca,czb,za,zba,ade}, ���� {zba,za,bca,ade,czb}��
* ���ͣ�
* �����µ��ֵ����������{zba,za,bca,ade,czb}��
*/
class Solution {
public:
	/**
	* @param alphabet: the new alphabet
	* @param words: the original string array
	* @return: the string array after sorting
	*/
	vector<string> wordSort(string &alphabet, vector<string> &words) {
		// Write your code here
		if (alphabet.empty() || words.empty() || words[0].empty())
			return words;
		vector<int> aTob(26), bToa(26);
		//��ԭ�ֵ䵽���ֵ�
		for (int i = 0; i < 26; ++i)
			aTob[i] = alphabet[i];
		//�����ֵ䵽ԭ�ֵ�
		for (int i = 0; i < 26; ++i)
			bToa[alphabet[i] - 'a'] = 'a' + i;
		//�Ƚ�Ԫ�ض�ת�����ֵ�,��������,֮����ת�����ֵ�
		for (auto &c : words)
		{
			for (auto &t : c)
				t = bToa[t - 'a'];
		}
		sort(words.begin(), words.end());
		for (auto &c : words)
		{
			for (auto &t : c)
				t = aTob[t - 'a'];
		}
		return words;
	}
};
#endif