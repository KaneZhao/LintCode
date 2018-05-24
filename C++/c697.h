#ifndef C697_H
#define C697_H
#include<iostream>
#include<set>
#include<math.h>
using namespace std;
/*
  *Given a integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.
  *
  *Example
  *Given n = 5
  *Return true // 1 * 1 + 2 * 2 = 5
  *
  *Given n = -5
  *Return false
*/
class Solution {
public:
	/*
	* @param : the given number
	* @return: whether whether there're two integers
	*/
	bool checkSumOfSquareNumbers(int num) {
		// write your code here
		if (num < 0)
			return false;
		int n = (int)sqrt(num);
		set<int> set;
		for (int i = 0; i <= n; ++i)
			set.insert(i*i);
		for (auto it = set.begin(); it != set.end(); ++it)
		{
			if (set.find(num - *it) != set.end())
			{
				return true;
			}
		}
		return false;
	}
};
#endif