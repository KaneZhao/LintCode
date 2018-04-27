#ifndef C972_H
#define C972_H
#include<iostream>
#include<vector>
using namespace std;
/*
传递消息

给一个公司的人员信息，第i个人传递消息的时间花费为t[i]，下属名单为list[i]，当某人接到消息后他会马上传递给他的所有下属。0号人物是CEO。现在CEO发布了一个消息传递下去，问公司里面所有人都收到消息的时间是多少？

注意事项
公司人数为n，n <= 1000。
每个人可以有多个下属，但只会有一个上级。
时间t[i] <= 10000。
下属为-1代表没有下属。

样例
给出 t = [1,2,3], list = [[1,2],[-1],[-1]], 返回 1。

解释：
消息从CEO开始传递，到1号、2号人物时时间为1，此时公司所有人都接到消息了。
给出 t = [1,2,1,4,5], list = [[1,2],[3,4],[-1],[-1],[-1]], 返回 3。

解释：
消息从CEO开始传递，到1、2号人物时时间为1，到3号人物时间为3，消息经2传递到4 比 经1传递到4更快，所以传递到4的时间为2。最后在时间为3时所有人都收到消息了。
*/
class Solution {
public:
	/**
	* @param t: the time of each employee to pass a meeage
	* @param subordinate: the subordinate of each employee
	* @return: the time of the last staff recieve the message
	*/
	int deliverMessage(vector<int> &t, vector<vector<int>> &subordinate) {
		// Write your code here
		if (t.empty() || subordinate.empty())
			return 0;
		int len = t.size();
		vector<int> staff(len, 0);//staff[i]表示消息传递到i员工所需要的时间
		helper(0, staff, t, subordinate);
		int res = 0;
		for (auto c : staff)
		{
			res = c > res ? c : res;
		}
		return res;
	}
	void helper(int start, vector<int> &staff, vector<int> &t, vector<vector<int>> &subordinate)
	{
		for (int i = 0; i < subordinate[start].size(); ++i)
		{
			//对于员工i的每个下属,收到消息的时间为员工i收到消息的时间+消息传递时间
			if (subordinate[start][i] != -1)
			{
				staff[subordinate[start][i]] = staff[start] + t[start];
				helper(subordinate[start][i], staff, t, subordinate);
			}
			else
				return;
		}
	}
};
#endif