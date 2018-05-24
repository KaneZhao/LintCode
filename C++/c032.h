#ifndef C32_H
#define C32_H
#include<string>
#include<map>
using namespace std;
/*
* 最小子串覆盖
*
* 给定一个字符串source和一个目标字符串target，在字符串source中找到包括所有目标字符串字母的子串。
* 注意事项
* 如果在source中没有这样的子串，返回""，如果有多个这样的子串，返回起始位置最小的子串。
* 说明
* 在答案的子串中的字母在目标字符串中是否需要具有相同的顺序？
* ——不需要。
* 样例
* 出source = "ADOBECODEBANC"，target = "ABC" 满足要求的解  "BANC"
* 挑战
* 要求时间复杂度为O(n)
*/
class Solution {
public:
	/**
	* @param source : A string
	* @param target: A string
	* @return: A string denote the minimum window, return "" if there is no such a string
	*/
	string minWindow(string &source, string &target) {
		// write your code here
		if (source.empty() || target.empty())
			return "";
		int slen = source.size();
		int tlen = target.size();
		//beg,end分别表示结果的开始和结束位置
		int beg = -1, end = slen, minLen = slen, len = 0;
		map<char, int> s, t;
		//t存放target中的字符和其出现次数
		for (auto c : target)
			t[c]++;
		for (int i = 0, start = 0; i < slen; ++i)
		{
			s[source[i]]++;
			//当t中的字符在s中的出现次数小于在t中的出现次数
			//len++
			if (s[source[i]] <= t[source[i]])
				++len;
			//len=tlen,表示目前包含target的所有字母
			if (len == tlen)
			{
				//从开头跳过无用的字符(此字符出现次数多于在target中的出现次数)
				//无用字符的出现次数减一,start向后移一位
				while (start<i&&s[source[start]]>t[source[start]])
				{
					s[source[start]]--;
					start++;
				}
				//寻找最小长度
				if (i - start < minLen)
				{
					minLen = i - start;
					beg = start;
					end = i;
				}
				//从start后一位开始继续寻找满足要求的字符串
				//由于在start后一位重新开始,先前的source[start]的出现次数减一,字符串长度减一
				s[source[start++]]--;
				len--;
			}
		}
		if (beg == -1)
			return "";
		else
			return source.substr(beg, end - beg + 1);
	}
};
#endif