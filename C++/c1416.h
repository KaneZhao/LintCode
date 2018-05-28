#ifndef C1416_H
#define C1416_H
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
* ǰһ����
*
* ����
* ��һ�����飬����ÿһ��Ԫ�أ��ҳ���֮ǰ��һ������С��Ԫ�ص�ֵ�����û�У������������
* ��������鳤��Ϊn��n <= 100000��
* Ԫ�صĴ�СΪx��x <= 1000000��
* ����
* ���� list = [2,3,6,1,5,5]������ [2,2,3,1,1,1]��
* ���ͣ�
* �������⣬�ҳ�ÿ������ǰ���һ������С��Ԫ�ء�
* ���� list = [6,3,1,2,5,10,9,15]������[6,3,1,1,2,5,5,9]��
* ���ͣ�
* �������⣬�ҳ�ÿ������ǰ���һ������С��Ԫ�ء�
*/
class Solution {
public:
	/**
	* @param num: The arry you should handle
	* @return: Return the array
	*/
	vector<int> getPreviousNumber(vector<int> &num) {
		// Write your code here
		if (num.empty())
			return num;
		stack<int> s;
		vector<int> res;//�������ս��
		s.push(num[0]);
		res.push_back(num[0]);
		//����Ԫ��num[i],���s��ջ��Ԫ�ش���num[i],��ջ
		//��ջ��,����num[i]ǰû�б���С��Ԫ��,num[i]ѹջ����ӵ�res
		//����,��ջ����ӵ�res,����num[i]ѹջ
		for (int i = 1; i < num.size(); ++i)
		{
			while (!s.empty()&&num[i]<=s.top())
			{
				s.pop();
			}
			if (s.empty())
			{
				s.push(num[i]);
				res.push_back(num[i]);
			}
			else
			{
				res.push_back(s.top());
				s.push(num[i]);
			}
		}
		return res;
	}
};
#endif