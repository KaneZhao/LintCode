#ifndef C819_H
#define C819_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 单词排序
* 
* 给一个新的字母表，如{c,b,a,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}，根据新的字母表排序字符串数组。
* 注意事项
* 输入的单词长度不超过100。
* 输入的单词总数不超过10000。
* 可以认为，输入的新字母表即一个长度为26的字符串。
* 保证题目只会出现小写字母。
* 样例
* 给出 Alphabet = {c,b,a,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}, String array = {cab,cba,abc}, 返回 {cba,cab,abc}。
* 解释：
* 根据新的字典序，排序输出{cba,cab,abc}。
* 给出 Alphabet = {z,b,a,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,c}, String array = {bca,czb,za,zba,ade}, 返回 {zba,za,bca,ade,czb}。
* 解释：
* 根据新的字典序，排序输出{zba,za,bca,ade,czb}。
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
		//由原字典到新字典
		for (int i = 0; i < 26; ++i)
			aTob[i] = alphabet[i];
		//由新字典到原字典
		for (int i = 0; i < 26; ++i)
			bToa[alphabet[i] - 'a'] = 'a' + i;
		//先将元素都转到旧字典,进行排序,之后再转到新字典
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