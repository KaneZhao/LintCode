#ifndef C685_H
#define C685_H
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
/*
* ��һ��������������,дһ������������ֹ���ֵ���ʱ�ĵ�һ��Ψһ���֣�������ֹ���֣�,
* �������ֹ����ǰ��Ψһ���ֻ����Ҳ��������ֹ����, ���� -1.
* 
* ����
* ��һ�������� [1, 2, 2, 1, 3, 4, 4, 5, 6] �Լ�һ������ 5, ���� 3
* ��һ�������� [1, 2, 2, 1, 3, 4, 4, 5, 6] �Լ�һ������ 7, ���� -1
*/
class Solution {
public:
	/*
	* @param : a continuous stream of numbers
	* @param : a number
	* @return: returns the first unique number
	*/
	int firstUniqueNumber(vector<int> nums, int number) {
		// Write your code here
		if (nums.empty())
			return -1;
		set<int> dic;    //��ų��ֵ���������
		set<int> set;    //����������γ��ֵ�����
		queue<int> que;  //��ŵ�һ�γ��ֵ�����
		bool flag = true;//�ж��Ƿ��ҵ�number
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != number)
			{
				if (dic.find(nums[i]) == dic.end())
				{
					que.push(nums[i]);
					dic.insert(nums[i]);
				}
				else
				{
					set.insert(nums[i]);
					//ֻҪ��ͷԪ�س�����set��,��ɾ��
					while (!que.empty()&&set.find(que.front()) != set.end())
					{
						que.pop();
					}
				}
			}
			else
			{
				flag = false;
				//��number��һ�γ���,���;����,�����ڶ�ͷ,��ɾ����ͷ
				if (dic.find(nums[i]) == dic.end())
					que.push(nums[i]);
				else
				{
					if (que.front() == nums[i])
						que.pop();
				}
				break;
			}
		}
		if (flag)
			return -1;
		else
			return que.empty() ? -1 : que.front();
	}
};
#endif