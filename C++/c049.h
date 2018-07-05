#ifndef C49_H
#define C49_H
#include<string>
#include<iostream>
using namespace std;
/*
* 字符大小写排序
* 
* 描述
* 给定一个只包含字母的字符串，按照先小写字母后大写字母的顺序进行排序。
* 小写字母或者大写字母他们之间不一定要保持在原始字符串中的相对位置。
* 样例
* 给出"abAcD"，一个可能的答案为"acbAD"
* 挑战
* 在原地扫描一遍完成
*/
class Solution {
public:
	/*
	* @param chars: The letter array you should sort by Case
	* @return: nothing
	*/
	void sortLetters(string &chars) {
		// write your code here
		if (chars.empty())
			return;
		int left = 0, right = chars.size() - 1;
		//两根指针,在chars[left]为大写字母,chars[right]为小写字母的情况下,交换
		//其余情况改变left或right的值
		while (left < right)
		{
			if (isupper(chars[left]))
			{
				if (isupper(chars[right]))
					right--;
				else
				{
					swap(chars[left], chars[right]);
					left++;
					right--;
				}
			}
			else
			{
				if (isupper(chars[right]))
				{
					left++;
					right--;
				}
				else
					left++;
			}
		}
	}
};
#endif