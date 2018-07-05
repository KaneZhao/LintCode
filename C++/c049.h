#ifndef C49_H
#define C49_H
#include<string>
#include<iostream>
using namespace std;
/*
* �ַ���Сд����
* 
* ����
* ����һ��ֻ������ĸ���ַ�����������Сд��ĸ���д��ĸ��˳���������
* Сд��ĸ���ߴ�д��ĸ����֮�䲻һ��Ҫ������ԭʼ�ַ����е����λ�á�
* ����
* ����"abAcD"��һ�����ܵĴ�Ϊ"acbAD"
* ��ս
* ��ԭ��ɨ��һ�����
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
		//����ָ��,��chars[left]Ϊ��д��ĸ,chars[right]ΪСд��ĸ�������,����
		//��������ı�left��right��ֵ
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