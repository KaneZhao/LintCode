#ifndef C421_H
#define C421_H
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
/*
* 简化路径
*
* 给定一个文档(Unix-style)的完全路径，请进行路径简化。
*
* 样例
* "/home/", => "/home"
* "/a/./b/../../c/", => "/c"
* 挑战
* 你是否考虑了 路径 = "/../" 的情况？
* 在这种情况下，你需返回"/"。
* 此外，路径中也可能包含双斜杠'/'，如 "/home//foo/"。
* 在这种情况下，可忽略多余的斜杠，返回 "/home/foo"。
*/
class Solution {
public:
	/*
	* @param path: the original path
	* @return: the simplified path
	*/
	string simplifyPath(string &path) {
		// write your code here
		if (path.empty())
			return path;
		stack<string> stack;
		string str;
		string res;
		//字符串str是“..”，则出栈；若str是“.”，由于是表示本级，不做操作；其他情况，str入栈
		for (int i = 0; i < path.size(); ++i)
		{
			if (path[i] == '/'&&!str.empty())
			{
				if (str == "..")
				{
					if (!stack.empty())
						stack.pop();
				}
				else if (str == ".")
				{
				}
				else
					stack.push(str);
				str.clear();
			}
			if (isalnum(path[i]))
				str += path[i];
			if (path[i] == '.')
				str += path[i];
		}
		//利用栈中的值构建res
		while (!stack.empty())
		{
			res = "/" + stack.top() + res;
			stack.pop();
		}
		//特殊处理"/."和"/.."
		if (!str.empty())
		{
			if (str == "."||str=="..")
				str.clear();
			res += "/" + str;
		}
		return res.empty()? "/" : res;
	}
};
#endif