#ifndef C123_H
#define C123_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
* ��������
*
* ����һ����ά����ĸ���һ�����ʣ�Ѱ����ĸ���������Ƿ����������ʡ�
* ���ʿ����ɰ�˳������ڵ�Ԫ����ĸ��ɣ��������ڵ�Ԫָ����ˮƽ���ߴ�ֱ�������ڡ�ÿ����Ԫ�е���ĸ���ֻ��ʹ��һ�Ρ�
* ����
* ����board =
* [
* "ABCE",
* "SFCS",
* "ADEE"
* ]
* word = "ABCCED"�� ->���� true,
* word = "SEE"��-> ���� true,
* word = "ABCB"�� -> ���� false.
*/
class Solution {
public:
	/**
	* @param board: A list of lists of character
	* @param word: A string
	* @return: A boolean
	*/
	bool exist(vector<vector<char> > &board, string word) {
		// write your code here
		if (board.empty() || word.empty())
			return false;
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (searchWord(board, i, j, 0, word))
					return true;
			}
		}
		return false;
	}
	bool searchWord(vector<vector<char>> &v, int i, int j, int pos, string word)
	{
		if (pos >= word.size())
			return true;
		if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] != word[pos])
			return false;
		v[i][j] ^= 100;//����ѭ������
		//�ж������������Ƿ���������λ��
		bool res = searchWord(v, i - 1, j, pos + 1, word) || searchWord(v, i + 1, j, pos + 1, word) ||
			searchWord(v, i, j - 1, pos + 1, word) || searchWord(v, i, j + 1, pos + 1, word);
		v[i][j] ^= 100;//�ݹ��,�����ָֻ�
		return res;
	}
};
#endif