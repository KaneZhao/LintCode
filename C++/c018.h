#ifndef C18_H
#define C18_H
#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const int a, const int b)
{
	return a > b;
}
class Solution {
public:
	/**
	* @param nums: A s of numbers.
	* @return: A list of lists. All valid subss.
	*/
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return{ {} };
		//��nums����ʹ�䵥������
		sort(nums.begin(), nums.end(), cmp);
		//����nums��ĩβԪ��,��s��resΪ��ʱ,���{},{nums.back()}
		//��s��Ϊ��,����res,��nums.back()��ӵ�Ԫ�ز���Ԫ����ӵ�res
		while (!nums.empty())
		{
			if (s.empty())
			{
				s.insert({});
				s.insert({ nums.back() });
				res.push_back({});
				res.push_back({ nums.back() });
			}
			else
			{
				int len = res.size();
				for (int i = 0; i < len; ++i)
				{
					vector<int> temp = res[i];
					temp.push_back(nums.back());
					if (s.find(temp) == s.end())
					{
						res.push_back(temp); 
						s.insert(temp);
					}
				}
			}
			nums.pop_back();
		}
		return res;
	}
	set<vector<int>> s;//����Ѿ����ֵĽ��
	vector<vector<int>> res;//������ս��
};


#endif