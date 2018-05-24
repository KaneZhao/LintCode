#ifndef C889_H
#define C889_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
* Sentence Screen Fitting
*
* Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.
*
* ע������
* A word cannot be split into two lines.
* The order of words in the sentence must remain unchanged.
* Two consecutive words in a line must be separated by a single space.
* Total words in the sentence won't exceed 100.
* Length of each word is greater than 0 and won't exceed 10.
* 1 �� rows, cols �� 20,000.
* ����
* Given rows = 2, cols = 8, sentence = ["hello", "world"], retrun 1.
* Explanation:
* hello---
* world---
* The character '-' signifies an empty space on the screen.
* Given rows = 3, cols = 6, sentence = ["a", "bcd", "e"], return 2.
* Explanation:
* a-bcd-
* e-a---
* bcd-e-
* The character '-' signifies an empty space on the screen.
*/
class Solution {
public:
	/**
	* @param sentence: a list of string
	* @param rows: an integer
	* @param cols: an integer
	* @return: return an integer, denote times the given sentence can be fitted on the screen
	*/
	int wordsTyping(vector<string> &sentence, int rows, int cols) {
		// Write your code here
		if (sentence.empty())
			return 0;
		int res = 0;
		int len = sentence.size();
		int i = 0, j = 0;
		int k = 0;
		//����λ��j���Դ���ַ���sentence[k]�һ���λ�ô����һ������(����)
		//j��ֵ���j + sentence[k].size() + 1,����ʱ�������������ͷ��ʼ����,�������������
		//����λ��j���Դ���ַ���sentence[k]���ǲ���ʣ��λ��
		//ֱ�ӵ���һ��,ͬʱ��������ı������
		//����λ��j��Ų����ַ���sentence[k],����һ��
		while (i < rows)
		{
			if (j + sentence[k].size() < cols - 1)
			{
				j += sentence[k].size() + 1;
				if (k == len - 1)
				{
					res++;
					k = 0;
				}
				else
					++k;
			}
			else if (j + sentence[k].size() == cols || j + sentence[k].size() == cols - 1)
			{
				i++;
				j = 0;
				if (k == len - 1)
				{
					res++;
					k = 0;
				}
				else
					++k;
			}
			else
			{
				++i;
				j = 0;
			}
		}
		return res;
	}
};
#endif