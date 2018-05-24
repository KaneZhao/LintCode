#ifndef C421_H
#define C421_H
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
/*
* ��·��
*
* ����һ���ĵ�(Unix-style)����ȫ·���������·���򻯡�
*
* ����
* "/home/", => "/home"
* "/a/./b/../../c/", => "/c"
* ��ս
* ���Ƿ����� ·�� = "/../" �������
* ����������£����践��"/"��
* ���⣬·����Ҳ���ܰ���˫б��'/'���� "/home//foo/"��
* ����������£��ɺ��Զ����б�ܣ����� "/home/foo"��
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
		//�ַ���str�ǡ�..�������ջ����str�ǡ�.���������Ǳ�ʾ�������������������������str��ջ
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
		//����ջ�е�ֵ����res
		while (!stack.empty())
		{
			res = "/" + stack.top() + res;
			stack.pop();
		}
		//���⴦��"/."��"/.."
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