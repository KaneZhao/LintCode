#ifndef C608_H
#define C608_H
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
* ������-���������������
*
* ����һ���Ѿ����������е����飬�ҵ�������ʹ���Ǽ������ĺ͵����ض�����
* ����Ӧ�÷��������������±꣬index1����С��index2��ע�ⷵ�ص�ֵ���� 0-based��
* ע������
* ����Լ���ÿ������պ�ֻ��һ����
* ����
* ��������Ϊ [2,7,11,15] ��target = 9
* ���� [1,2]
*/
class Solution {
public:
	/*
	* @param nums: an array of Integer
	* @param target: target = nums[index1] + nums[index2]
	* @return: [index1 + 1, index2 + 1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		vector<int> res;
		map<int, int> map;//���Ԫ��������ִ���
		for (auto c : nums)
		{
			map[c]++;
		}
		int pos1 = 0, pos2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			map[nums[i]]--;
			//��map���ҵ���nums[i]��Ϊtarget����,���ұ�֤������
			if (map.find(target - nums[i]) != map.end() && map[target - nums[i]]>0)
			{
				pos1 = i;
				break;
			}
			map[nums[i]]++;
		}
		//�Ӻ���ǰ����,�ҵ�target-nums[pos1]
		for (int j = nums.size() - 1; j >= 0; --j)
		{
			if (nums[j] == target - nums[pos1])
			{
				pos2 = j;
				break;
			}
		}
		res.push_back(pos1 + 1);
		res.push_back(pos2 + 1);
		return res;
	}
};
#endif