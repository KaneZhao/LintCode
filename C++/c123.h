#ifndef C123_H
#define C123_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
* 单词搜索
*
* 给出一个二维的字母板和一个单词，寻找字母板网格中是否存在这个单词。
* 单词可以由按顺序的相邻单元的字母组成，其中相邻单元指的是水平或者垂直方向相邻。每个单元中的字母最多只能使用一次。
* 样例
* 给出board =
* [
* "ABCE",
* "SFCS",
* "ADEE"
* ]
* word = "ABCCED"， ->返回 true,
* word = "SEE"，-> 返回 true,
* word = "ABCB"， -> 返回 false.
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
		v[i][j] ^= 100;//避免循环搜索
		//判断其左右上下是否存在满足的位置
		bool res = searchWord(v, i - 1, j, pos + 1, word) || searchWord(v, i + 1, j, pos + 1, word) ||
			searchWord(v, i, j - 1, pos + 1, word) || searchWord(v, i, j + 1, pos + 1, word);
		v[i][j] ^= 100;//递归后,将数字恢复
		return res;
	}
};
#endif