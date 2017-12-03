#ifndef C704_H
#define C704_H
#include<iostream>
#include<string>
#include<set>
#include<cmath>
using namespace std;
class Solution {
public:
	/*
	* @param : number of lights
	* @param : number of operations
	* @return: the number of status
	*/
	int flipLights(int n, int m) {
		// write your code here
		if (n <= 0)
			return 0;
		if (m <= 0)
			return 1;
		if (n>=3&&m >= 3)
			return 8;
		set<string> set;	
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				for (int k = 0; k <= m; ++k)
				{
					if (m - i - j - k >= 0)
					{
						string str(n, '1');
						int num1 = i, num2 = j, num3 = k, num4 = m - i - j - k;
						while (num1 > 0)
						{
							button1(str);
							num1--;
						}
						while (num2 > 0)
						{
							button2(str);
							num2--;
						}
						while (num3 > 0)
						{
							button3(str);
							num3--;
						}
						while (num4 > 0)
						{
							button4(str);
							num4--;
						}
						set.insert(str);
					}
				}
			}
		}
		return set.size();
	}
	void button1(string &s)
	{
		for (auto &c : s)
		{
			if (c == '0')
				c = '1';
			else
				c = '0';
		}
	}
	void button2(string &s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if ((i + 1) % 2 == 0)
			{
				if (s[i] == '0')
					s[i] = '1';
				else
					s[i] = '0';
			}
		}
	}
	void button3(string &s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if ((i + 1) % 2 != 0)
			{
				if (s[i] == '0')
					s[i] = '1';
				else
					s[i] = '0';
			}
		}
	}
	void button4(string &s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if ((i + 1) % 3 == 1)
			{
				if (s[i] == '0')
					s[i] = '1';
				else
					s[i] = '0';
			}
		}
	}
};
#endif